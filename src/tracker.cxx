#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
//#include "pixy.h"
#include "ShapeType.h"
#include "ShapeTypeSupport.h"
#include "ServoControl.h"
#include "ServoControlSupport.h"

#include "ndds/ndds_cpp.h"

static bool run_flag = true;
static bool got_matched_publisher = false;
static bool got_matched_subscriber = false;

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
#define INDEX_VIOLET 6

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
void initialize_gimbals(void);
int track (int domainId, unsigned int);
int main (int argc, char *argv[]);

//-------------------------------------------------------------------
// We'll need one of these for pan, and one for tilt.  Holds
// variables for running the tracking algorithm
//-------------------------------------------------------------------
struct Gimbal {
  int32_t position;
  int32_t previous_error;
  int32_t proportional_gain;
  int32_t derivative_gain;
};

struct Gimbal pan;
struct Gimbal tilt;


//-------------------------------------------------------------------
// handle_SIGINT - sets flag for orderly shutdown on Ctrl-C
//-------------------------------------------------------------------
void handle_SIGINT(int unused)
{
  // On CTRL+C - abort! //

  run_flag = false;
}

//-------------------------------------------------------------------
// Setup the gimbal control structures
//-------------------------------------------------------------------
void initialize_gimbals(void)
{
	pan.position = PIXY_RCS_CENTER_POS;
	pan.previous_error     = 0x80000000L;
	pan.proportional_gain  = PAN_PROPORTIONAL_GAIN;
	pan.derivative_gain    = PAN_DERIVATIVE_GAIN;
	tilt.position          = PIXY_RCS_CENTER_POS;
	tilt.previous_error    = 0x80000000L;
	tilt.proportional_gain = TILT_PROPORTIONAL_GAIN;
	tilt.derivative_gain   = TILT_DERIVATIVE_GAIN;
}

//-------------------------------------------------------------------
// This is the control loop for each axis of the cam control (pan/tilt)
//-------------------------------------------------------------------
void gimbal_update(struct Gimbal *  gimbal, int32_t error)
{
	long int velocity;
	int32_t  error_delta;
	int32_t  P_gain;
	int32_t  D_gain;

	if(gimbal->previous_error != 0x80000000L)
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

//-------------------------------------------------------------------
// Listener class for servo control writer
//-------------------------------------------------------------------
class ServoTypeListener : public DDSDataWriterListener
{
public:
	virtual void on_offered_deadline_missed (
			DDSDataWriter *writer,
			const DDS_OfferedDeadlineMissedStatus &status)  {}

	virtual void	 on_liveliness_lost (DDSDataWriter *writer,
			const DDS_LivelinessLostStatus &status) {}

	virtual void on_offered_incompatible_qos (DDSDataWriter *writer,
			const DDS_OfferedIncompatibleQosStatus &status) {}

	virtual void on_publication_matched (DDSDataWriter *writer,
			const DDS_PublicationMatchedStatus &status);

	virtual void on_reliable_writer_cache_changed (DDSDataWriter *writer,
			const DDS_ReliableWriterCacheChangedStatus &status) {}

	virtual void on_reliable_reader_activity_changed (DDSDataWriter *writer,
			const DDS_ReliableReaderActivityChangedStatus &status) {}

	virtual void on_instance_replaced (DDSDataWriter *writer,
			const DDS_InstanceHandle_t &handle) {}

	virtual void on_application_acknowledgment (DDSDataWriter *writer,
			const DDS_AcknowledgmentInfo &info) {}

	virtual void on_service_request_accepted (DDSDataWriter *writer,
			const DDS_ServiceRequestAcceptedStatus &status) {}
};

void ServoTypeListener::on_publication_matched(DDSDataWriter *writer, const DDS_PublicationMatchedStatus &status)
{
	ServoControlDataWriter *servo_writer = NULL;
	DDS_ReturnCode_t retcode;

	servo_writer = ServoControlDataWriter::narrow(writer);
	if (NULL==servo_writer) return;

	printf("\n");
	printf("Subs: %d %d\n", status.current_count, status.current_count_change);
	if (status.current_count > 0)
		got_matched_subscriber = true;
	else
		got_matched_subscriber = false;

	return;
}

//-------------------------------------------------------------------
// Listener class for data reader
//-------------------------------------------------------------------
class ShapeTypeListener : public DDSDataReaderListener
{
public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus & /*status*/);

    virtual void on_data_available(DDSDataReader* reader){}

};


void ShapeTypeListener::on_subscription_matched(DDSDataReader *reader, const DDS_SubscriptionMatchedStatus &status)
{
	ShapeTypeExtendedDataReader *shape_reader = NULL;
	DDS_ReturnCode_t retcode;

	shape_reader = ShapeTypeExtendedDataReader::narrow(reader);
	if (NULL == shape_reader) return;

	printf("\n");
	printf("Pubs: %d %d\n", status.current_count, status.current_count_change);
	if (status.current_count > 0)
		got_matched_publisher = true;
	else
		got_matched_publisher = false;

	return;
}


//-------------------------------------------------------------------
// Shutdown in an orderly fashion
//-------------------------------------------------------------------
static int subscriber_shutdown (DDSDomainParticipant *participant)
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

    /* RTI Connext provides the finalize_instance() method on
    domain participant factory for people who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = -1;
    }
    */
    return status;

}

int track (int domainId, unsigned int tracked_channel)
{
	int status = 0;
	DDSDomainParticipant *participant = NULL;
	DDSSubscriber *subscriber = NULL;
	DDSPublisher *publisher = NULL;
	DDSTopic *shape_topic = NULL;
	DDSTopic *servo_topic = NULL;
	DDSDataReader *reader = NULL;
	DDSDataWriter *writer = NULL;
	DDS_ReturnCode_t retcode;
	ShapeTypeListener *shape_listener = new ShapeTypeListener;
	ServoTypeListener *servo_listener = new ServoTypeListener;
	const char *shape_type_name = NULL;
	const char *servo_type_name = NULL;
	ShapeTypeExtended shape;
	DDS_SampleInfo shape_info;
	ServoControl servo_control;
	DDS_InstanceHandle_t servo_handle = DDS_HANDLE_NIL;
	int pan_error;
	int tilt_error;
	int frame_count = 0;
	char channel_filter[50];

	// Create the domain participant
	participant = DDSTheParticipantFactory->create_participant_with_profile(domainId, "PixyTracker_Library", "PixyTracker_Active_Profile",
			NULL, DDS_STATUS_MASK_NONE);
//	participant = DDSTheParticipantFactory->create_participant(0, DDS_PARTICIPANT_QOS_DEFAULT,NULL,DDS_STATUS_MASK_NONE);
	if (participant == NULL) {
		fprintf(stderr, "create participant error\n");
		subscriber_shutdown(participant);
		return -1;
	}

	// Create a publisher and a subscriber
	subscriber = participant->create_subscriber(DDS_SUBSCRIBER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	publisher  = participant->create_publisher (DDS_PUBLISHER_QOS_DEFAULT,  NULL, DDS_STATUS_MASK_NONE);
	if ((subscriber == NULL) || (publisher == NULL))
	{
        fprintf(stderr, "create subscriber/publisher error\n");
        subscriber_shutdown(participant);
        return -1;

	}

	// Register the types
	shape_type_name = ShapeTypeExtendedTypeSupport::get_type_name();
	servo_type_name = ServoControlTypeSupport::get_type_name();
	ShapeTypeExtendedTypeSupport::register_type(participant, shape_type_name);
	ServoControlTypeSupport::register_type(participant, servo_type_name);

	// Create topics
	shape_topic = participant->create_topic("Circle", shape_type_name, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	servo_topic = participant->create_topic(DEFAULT_CAM_CONTROL_TOPIC_NAME, servo_type_name, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

	// Create a content filtered topic with the tracked color name "color MATCH 'GREEN'"
	DDSContentFilteredTopic *cft = NULL;
    const DDS_StringSeq noFilterParams;

	if (shape_topic)
	{
		sprintf(channel_filter, "color MATCH '%s'", sigName[tracked_channel]);
		cft = participant->create_contentfilteredtopic("TrackedShape", shape_topic, channel_filter, noFilterParams);
		if (cft == NULL)
		{
	        fprintf(stderr, "create content filtered topic\n");
	        subscriber_shutdown(participant);
	        return -1;
		}
	}

	// Create a data reader and a data writer
	reader = participant->create_datareader_with_profile(cft, "PixyTracker_Library", "PixyTracker_Active_Profile", shape_listener, DDS_STATUS_MASK_ALL);
	writer = participant->create_datawriter_with_profile(servo_topic, "PixyTracker_Library", "PixyTracker_Active_Profile", servo_listener, DDS_STATUS_MASK_ALL);
	if ((reader == NULL) || (writer == NULL))
	{
        fprintf(stderr, "create reader and writer\n");
        subscriber_shutdown(participant);
        return -1;
	}


	ShapeTypeExtendedDataReader *track_reader = ShapeTypeExtendedDataReader::narrow(reader);
	ServoControlDataWriter *servo_writer = ServoControlDataWriter::narrow(writer);
	if ((track_reader == NULL) || (servo_writer == NULL))
	{
        fprintf(stderr, "create track reader and servo writer\n");
        subscriber_shutdown(participant);
        return -1;
	}

	ServoControl_initialize(&servo_control);
	servo_control.pan = PIXY_RCS_CENTER_POS;
	servo_control.tilt = PIXY_RCS_CENTER_POS;
	servo_control.frequency = SERVO_FREQUENCY_HZ;

	ShapeTypeExtended_initialize(&shape);

	while (run_flag == true)
	{
		// Get the latest sample
		retcode = track_reader->take_next_sample(shape, shape_info);

		if ((retcode == DDS_RETCODE_OK) && (shape_info.valid_data == RTI_TRUE))
		{
			// Control the pan & tilt
			pan_error = PIXY_X_CENTER - shape.x;
			tilt_error = shape.y - PIXY_Y_CENTER;
			gimbal_update(&pan, pan_error);
			gimbal_update(&tilt, tilt_error);

			servo_control.pan = (unsigned short) pan.position;
			servo_control.tilt = (unsigned short) tilt.position;
			servo_writer->write(servo_control, servo_handle);

			if (frame_count++ > 10)
			{
				frame_count = 0;
				printf("P: %d T: %d   \r", pan.position, tilt.position);
				fflush(stdout);
				}
		}
	}
	status = subscriber_shutdown(participant);
	return status;
}
//-------------------------------------------------------------------
// Program entry point
//-------------------------------------------------------------------
int main (int argc, char *argv[])
{
    int domainId = 53;
    int return_value;
    unsigned int trackedChannel = INDEX_GREEN;

    signal(SIGINT, handle_SIGINT);

    printf("PIXY TRACKER: %s %s\n", __DATE__, __TIME__);
    printf("DomainID: %d\n", domainId);

    if (argc > 1)
    {
        for (int count = 1; count < argc; count++)
        {
            for (int sigs = 0; sigs < NUM_SIGS; sigs++)
            {
                if (strcmp(argv[count], sigName[sigs])== 0)
                {
                    trackedChannel = sigs;
                    break;
                }
            }
        }
    }

    if (trackedChannel > NUM_SIGS) trackedChannel = INDEX_GREEN;
    printf("Tracking %s\n", sigName[trackedChannel]);
    initialize_gimbals();
    track(domainId, trackedChannel);

}
