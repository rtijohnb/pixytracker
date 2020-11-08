#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>

#include "ndds/ndds_cpp.h"
#include <pthread.h>

static bool run_flag = true;

#define NUM_SIGS 7

const char *sigName[] = {
    "RED",
    "ORANGE",
    "YELLOW",
    "GREEN",
    "CYAN",
    "BLUE",
    "PURPLE"
};

#define INDEX_RED  0
#define INDEX_ORANGE 1
#define INDEX_YELLOW 2
#define INDEX_GREEN 3
#define INDEX_CYAN 4
#define INDEX_BLUE 5
#define INDEX_PURPLE 6

#define S0_LOWER_LIMIT -200
#define S0_UPPER_LIMIT 200
#define S1_LOWER_LIMIT -200
#define S1_UPPER_LIMIT 200
#define SERVO_FREQUENCY_HZ 60

// Pixy x-y position values
 #define PIXY_MIN_X                  0
 #define PIXY_MAX_X                  319
 #define PIXY_MIN_Y                  0
 #define PIXY_MAX_Y                  199

 // RC-servo values
 #define PIXY_RCS_MIN_POS            0
 #define PIXY_RCS_MAX_POS            1000
 #define PIXY_RCS_CENTER_POS         ((PIXY_RCS_MAX_POS-PIXY_RCS_MIN_POS)/2)

// PID control parameters //
//#define PAN_PROPORTIONAL_GAIN     400	// 400 350
//#define PAN_DERIVATIVE_GAIN       300	// 300 600
//#define TILT_PROPORTIONAL_GAIN    500	// 500 500
//#define TILT_DERIVATIVE_GAIN      300	// 400 700

#define PAN_PROPORTIONAL_GAIN     300	// 400 350
#define PAN_DERIVATIVE_GAIN       200	// 300 600
#define TILT_PROPORTIONAL_GAIN    350	// 500 500
#define TILT_DERIVATIVE_GAIN      300	// 400 700

#define SHAPE_X_MIN 0
#define SHAPE_X_MAX 222
#define SHAPE_Y_MIN 0
#define SHAPE_Y_MAX 252

#define PIXY_X_CENTER              ((SHAPE_X_MAX-SHAPE_X_MIN)/2)
#define PIXY_Y_CENTER              ((SHAPE_Y_MAX-SHAPE_Y_MIN)/2)

// These values will keep the tracked ball centered over the orange dot over the "i" in "rti" in the Shapes demo.
// Useful if you're tracking the orange ball.
//#define PIXY_X_CENTER              (168)
//#define PIXY_Y_CENTER              (89)

// Local prototypes
void handle_SIGINT(int unused);
int track (int domainId, unsigned int);
int main (int argc, char *argv[]);

class Gimbal {
	public:
		Gimbal() {
			pan.position           = PIXY_RCS_CENTER_POS;
			pan.previous_error     = 0x80000000;
			pan.proportional_gain  = PAN_PROPORTIONAL_GAIN;
			pan.derivative_gain    = PAN_DERIVATIVE_GAIN;
			tilt.position          = PIXY_RCS_CENTER_POS;
			tilt.previous_error    = 0x80000000;
			tilt.proportional_gain = TILT_PROPORTIONAL_GAIN;
			tilt.derivative_gain   = TILT_DERIVATIVE_GAIN;
		}

		void update_pan (DDS_Long x) {
			int pan_error = PIXY_X_CENTER - x;
			update(&pan, pan_error);
		}
		void update_tilt (DDS_Long y) {
			int tilt_error = y - PIXY_Y_CENTER;
			update(&tilt, tilt_error);
		}

		int32_t get_pan_position()  { return pan.position; }
		int32_t get_tilt_position() { return tilt.position; }

	private:
		struct GimbalParams {
			int32_t position;
			int32_t previous_error;
			int32_t proportional_gain;
			int32_t derivative_gain;
		} pan, tilt;

		//-------------------------------------------------------------------
		// This calculates the position each axis of the cam control (pan/tilt)
		//-------------------------------------------------------------------
		void update(struct GimbalParams * gimbal, int32_t error) {

			long int velocity;
			int32_t  error_delta;
			int32_t  P_gain;
			int32_t  D_gain;

			if(gimbal->previous_error != 0x80000000)
			{
				error_delta = error - gimbal->previous_error;
				P_gain      = gimbal->proportional_gain;
				D_gain      = gimbal->derivative_gain;

				/* Using the proportional and derivative gain for the gimbal,
				calculate the change to the position.  */
				velocity = (error * P_gain + error_delta * D_gain) >> 10;

				gimbal->position += velocity;

				if (gimbal->position > PIXY_RCS_MAX_POS)
				{
					gimbal->position = PIXY_RCS_MAX_POS;
				} else if (gimbal->position < PIXY_RCS_MIN_POS)
				{
					gimbal->position = PIXY_RCS_MIN_POS;
				}
			}
			gimbal->previous_error = error;
		}
};

//-------------------------------------------------------------------
// handle_SIGINT - sets flag for orderly shutdown on Ctrl-C
//-------------------------------------------------------------------
void handle_SIGINT(int unused)
{
  // On CTRL+C - abort! //
  run_flag = false;
}

class WaitsetWriterInfo {
    // holds waitset info needed for the writer waitset processing thread
    public:
        DDSDynamicDataWriter * servo_writer;
		bool * run_flag;
} ;

void*  pthreadToProcWriterEvents(void *waitsetWriterInfo) {
    WaitsetWriterInfo * myWaitsetInfo;
    myWaitsetInfo = (WaitsetWriterInfo *)waitsetWriterInfo;
	DDSWaitSet *waitset = new DDSWaitSet();;
    DDS_ReturnCode_t retcode;
    DDSConditionSeq active_conditions_seq;

    printf("Created Writer Pthread\n");
    // Configure Waitset for Writer Status ****
    DDSStatusCondition *status_condition = myWaitsetInfo->servo_writer->get_statuscondition();
    if (status_condition == NULL) {
        printf("get_statuscondition error\n");
        goto end_writer_thread;
    }

    // Set enabled statuses
    retcode = status_condition->set_enabled_statuses(
            DDS_PUBLICATION_MATCHED_STATUS);
    if (retcode != DDS_RETCODE_OK) {
        printf("set_enabled_statuses error\n");
        goto end_writer_thread;
    }

    // Attach Status Conditions to the above waitset
    retcode = waitset->attach_condition(status_condition);
    if (retcode != DDS_RETCODE_OK) {
        printf("attach_condition error\n");
        goto end_writer_thread;
    }

    // wait() blocks execution of the thread until one or more attached
    
	// thread exits upon ^c or error
    while ((* myWaitsetInfo->run_flag) == true) {
        retcode = waitset->wait(active_conditions_seq, DDS_DURATION_INFINITE);
        /* We get to timeout if no conditions were triggered */
        if (retcode == DDS_RETCODE_TIMEOUT) {
            printf("Wait timed out!! No conditions were triggered.\n");
            continue;
        } else if (retcode != DDS_RETCODE_OK) {
            printf("wait returned error: %d\n", retcode);
            goto end_writer_thread;
        }

        /* Get the number of active conditions */
        int active_conditions = active_conditions_seq.length();

        for (int i = 0; i < active_conditions; ++i) {
            /* Compare with Status Conditions */
            if (active_conditions_seq[i] == status_condition) {
                DDS_StatusMask triggeredmask =
                        myWaitsetInfo->servo_writer->get_status_changes();

                if (triggeredmask & DDS_PUBLICATION_MATCHED_STATUS) {
					DDS_PublicationMatchedStatus st;
                	myWaitsetInfo->servo_writer->get_publication_matched_status(st);
					printf("\nServo Subs: %d %d\n", st.current_count, st.current_count_change);
                }
            } else {
                // writers can only have status condition
                printf ("False Writer Event Trigger");
            }
        }
	} // While (run_flag)
	end_writer_thread: // reached by ^C or an error
	printf("Writer Pthread Exiting\n");
	exit(0);
}

class WaitsetReaderInfo {
    // holds waitset info needed for the Reader waitset processing thread
    public:
        DDSDynamicDataReader * track_reader;
		DDSDynamicDataWriter * servo_writer; // tracker reader will do the writing
		bool * run_flag;
} ;

void*  pthreadToProcReaderEvents(void *waitsetReaderInfo) {
    WaitsetReaderInfo * myWaitsetInfo;
    myWaitsetInfo = (WaitsetReaderInfo *)waitsetReaderInfo;
	DDSStatusCondition *status_condition =  NULL;
	DDSReadCondition * read_condition = NULL;
	DDSWaitSet *waitset = new DDSWaitSet();
    DDS_ReturnCode_t retcode;
    DDSConditionSeq active_conditions_seq;
	DDS_DynamicDataSeq shape_data_seq;
	DDS_SampleInfoSeq shape_info_seq;
	DDS_DynamicData * servo_data = NULL;  // Reader thread publishes gimbal updates and writes vis servo_writer/data

	Gimbal gimbal;
	DDS_Long x;
	DDS_Long y;
	DDS_UnsignedShort frequency = SERVO_FREQUENCY_HZ;
	int frame_count = 0;

    printf("Created Reader Pthread\n");
	
    servo_data = myWaitsetInfo->servo_writer->create_data(DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (servo_data == NULL) {
        fprintf(stderr, "create_data error\n");
		goto end_reader_thread;
    } 
  
	retcode = servo_data->set_ushort("frequency", DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED, frequency);
	if (retcode != DDS_RETCODE_OK) {
		fprintf(stderr, "set frequency error\n");
		goto end_reader_thread;
	}
    // Create read condition
    read_condition = myWaitsetInfo->track_reader->create_readcondition(
            DDS_NOT_READ_SAMPLE_STATE,
            DDS_ANY_VIEW_STATE,
            DDS_ANY_INSTANCE_STATE);
    if (read_condition == NULL) {
        printf("create_readcondition error\n");
		goto end_reader_thread;
    }

    //  Get status conditions
    status_condition = myWaitsetInfo->track_reader->get_statuscondition();
    if (status_condition == NULL) {
        printf("get_statuscondition error\n");
 		goto end_reader_thread;
    }

    // Set enabled statuses
    retcode = status_condition->set_enabled_statuses(DDS_SUBSCRIPTION_MATCHED_STATUS);
    if (retcode != DDS_RETCODE_OK) {
        printf("set_enabled_statuses error\n");
 		goto end_reader_thread;
    }   

    /* Attach Read Conditions */
    retcode = waitset->attach_condition(read_condition);
    if (retcode != DDS_RETCODE_OK) {
        printf("attach_condition error\n");
		goto end_reader_thread;
    }

    /* Attach Status Conditions */
    retcode = waitset->attach_condition(status_condition);
    if (retcode != DDS_RETCODE_OK) {
        printf("attach_condition error\n");
		goto end_reader_thread;
    }

	while ((* myWaitsetInfo->run_flag) == true) {

       	retcode = waitset->wait(active_conditions_seq, DDS_DURATION_INFINITE);
        /* We get to timeout if no conditions were triggered */
        if (retcode == DDS_RETCODE_TIMEOUT) {
            printf("Tracker reader Wait timed out!! No conditions were triggered.\n");
            continue;
        } else if (retcode != DDS_RETCODE_OK) {
            printf("Tracker reader wait returned error: %d\n", retcode);
            goto end_reader_thread;
        }

        int active_conditions = active_conditions_seq.length();

        for (int i = 0; i < active_conditions; ++i) {

            if (active_conditions_seq[i] == status_condition) {
                /* Get the status changes so we can check which status
                 * condition triggered. */
                DDS_StatusMask triggeredmask =
                        myWaitsetInfo->track_reader->get_status_changes();

                /* Subscription matched */
                if (triggeredmask & DDS_SUBSCRIPTION_MATCHED_STATUS) {
                    DDS_SubscriptionMatchedStatus st;
                    myWaitsetInfo->track_reader->get_subscription_matched_status(st);
					printf("\nShapes Pubs: %d %d\n", st.current_count, st.current_count_change);
                }
            }

            /* Compare with Read Conditions */
            else if (active_conditions_seq[i] == read_condition) {

				// Get the latest samples
				retcode = myWaitsetInfo->track_reader->take(
							shape_data_seq, shape_info_seq, DDS_LENGTH_UNLIMITED,
							DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

				if (retcode == DDS_RETCODE_OK) {
					for (int i = 0; i < shape_data_seq.length(); ++i) {
						if (shape_info_seq[i].valid_data) {                       
							// Control the pan & tilt
							retcode=shape_data_seq[i].get_long(x, "x", DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED);
							if (retcode != DDS_RETCODE_OK) goto end_reader_thread;
							retcode=shape_data_seq[i].get_long(y, "y", DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED);
							if (retcode != DDS_RETCODE_OK) goto end_reader_thread;

							gimbal.update_pan(x);
							gimbal.update_tilt(y);

							retcode = servo_data->set_ushort("pan", DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED, gimbal.get_pan_position());
							if (retcode != DDS_RETCODE_OK) goto end_reader_thread;
							retcode = servo_data->set_ushort("tilt", DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED, gimbal.get_tilt_position());
							if (retcode != DDS_RETCODE_OK) goto end_reader_thread;
							retcode = myWaitsetInfo->servo_writer->write(* servo_data, DDS_HANDLE_NIL);

							if (frame_count++ > 10) {
								frame_count = 0;
								printf("P: %d T: %d   \r", gimbal.get_pan_position(), gimbal.get_tilt_position());
								fflush(stdout);
							}
						}
						retcode = myWaitsetInfo->track_reader->return_loan(shape_data_seq, shape_info_seq);
						if (retcode != DDS_RETCODE_OK) {
							fprintf(stderr, "return_loan error %d\n", retcode);
							goto end_reader_thread;
						}
					}
				} else if (retcode == DDS_RETCODE_NO_DATA) {
					continue;
				} else {
					fprintf(stderr, "take data error %d\n", retcode);
					goto end_reader_thread;
				}
			}
		}
	} // While (run_flag)
	end_reader_thread: // reached by ^C or an error
	printf("Reader Pthread Exiting\n");
	exit(0);
}

//-------------------------------------------------------------------
// Shutdown in an orderly fashion
//-------------------------------------------------------------------
static int participant_shutdown (DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    return status;
}

int track (unsigned int tracked_channel) {
	DDSDomainParticipant * participant = NULL;
	DDSDynamicDataWriter * servo_writer = NULL;
	DDSDynamicDataReader * track_reader = NULL;	
	DDS_Duration_t check_period = {1,0};
	int status = 0;

	// Create the domain participant from XML
	participant = DDSTheParticipantFactory->create_participant_from_config(
		"PixyTrackerParticipant_Library::PixyTrackerParticipant");
	if (participant == NULL) {
		fprintf(stderr, "create participant error\n");
		goto track_end;
	}

	servo_writer = DDSDynamicDataWriter::narrow(
		participant->lookup_datawriter_by_name("publisher::TrackerHostWriter")); // if Publisher name set in QoS file
        //participant->lookup_datawriter_by_name("publisher::servo_topic_writer"));
    if (servo_writer == NULL) {
        fprintf(stderr, "lookup_datawriter_by_name error\n"); 
		goto track_end;
    }

 	track_reader = DDSDynamicDataReader::narrow(
		participant->lookup_datareader_by_name("subscriber::TrackerHostReader")); // if Subscriber name set in QoS file
        //participant->lookup_datareader_by_name("subscriber::shape_topic_reader")); 
    if (track_reader == NULL) {
        fprintf(stderr, "lookup_datareader_by_name error\n");
		goto track_end;
    }

    // Turn up a waitset threads and hang on them for writer events and reader events and data
    WaitsetWriterInfo myWaitsetWriterInfo;
    myWaitsetWriterInfo.servo_writer = servo_writer;
	myWaitsetWriterInfo.run_flag = &run_flag;
    pthread_t wtid;
    pthread_create(&wtid, NULL, pthreadToProcWriterEvents, (void*) &myWaitsetWriterInfo);

    WaitsetReaderInfo myWaitsetReaderInfo;
    myWaitsetReaderInfo.track_reader = track_reader;
	myWaitsetReaderInfo.servo_writer = servo_writer; // tracker_reader does the writing
	myWaitsetReaderInfo.run_flag = &run_flag;
	pthread_t rtid;
    pthread_create(&rtid, NULL, pthreadToProcReaderEvents, (void*) &myWaitsetReaderInfo);

	// main loop - reading and writing done in reader thread so nothing to do here
	while (run_flag == true) {
		// do 3-way voting logic here?
		NDDSUtility::sleep(check_period); // check every 1 sec for a ^C to stop
	}
	track_end: // reached by ^C or an error
	status = participant_shutdown(participant);
	return status;
}
//-------------------------------------------------------------------
// Program entry point
//-------------------------------------------------------------------
int main (int argc, char *argv[]) {
    // Note the color is now set in the XML filter. 
	// ** TODO if a color is specified as arg v, Programatically change the filter parameter.
    unsigned int trackedChannel = INDEX_YELLOW;

    signal(SIGINT, handle_SIGINT);

    printf("PIXY TRACKER: %s %s\n", __DATE__, __TIME__);
    //printf("DomainID: %d\n", domainId);

    if (argc > 1) {
        for (int count = 1; count < argc; count++) {
            for (int sigs = 0; sigs < NUM_SIGS; sigs++) {
                if (strcmp(argv[count], sigName[sigs])== 0) {
                    trackedChannel = sigs;
                    break;
                }
            }
        }
    }

    if (trackedChannel > NUM_SIGS) trackedChannel = INDEX_GREEN;
    printf("Tracking %s\n", sigName[trackedChannel]);
    track(trackedChannel);
}
