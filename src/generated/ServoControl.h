

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServoControl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef ServoControl_1848045221_h
#define ServoControl_1848045221_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *ServoControlTYPENAME;

}

struct ServoControlSeq;
#ifndef NDDS_STANDALONE_TYPE
class ServoControlTypeSupport;
class ServoControlDataWriter;
class ServoControlDataReader;
#endif
class ServoControl 
{
  public:
    typedef struct ServoControlSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef ServoControlTypeSupport TypeSupport;
    typedef ServoControlDataWriter DataWriter;
    typedef ServoControlDataReader DataReader;
    #endif

    DDS_UnsignedShort   pan ;
    DDS_UnsignedShort   tilt ;
    DDS_UnsignedShort   frequency ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* ServoControl_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *ServoControl_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *ServoControl_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *ServoControl_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(ServoControlSeq, ServoControl);

NDDSUSERDllExport
RTIBool ServoControl_initialize(
    ServoControl* self);

NDDSUSERDllExport
RTIBool ServoControl_initialize_ex(
    ServoControl* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool ServoControl_initialize_w_params(
    ServoControl* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool ServoControl_finalize_w_return(
    ServoControl* self);

NDDSUSERDllExport
void ServoControl_finalize(
    ServoControl* self);

NDDSUSERDllExport
void ServoControl_finalize_ex(
    ServoControl* self,RTIBool deletePointers);

NDDSUSERDllExport
void ServoControl_finalize_w_params(
    ServoControl* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void ServoControl_finalize_optional_members(
    ServoControl* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool ServoControl_copy(
    ServoControl* dst,
    const ServoControl* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
static const DDS_Char * const DEFAULT_CAM_CONTROL_TOPIC_NAME= "pixy/servo_control";

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<ServoControl> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* ServoControl */

