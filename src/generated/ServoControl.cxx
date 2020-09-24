

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServoControl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "ServoControl.h"

#ifndef NDDS_STANDALONE_TYPE
#include "ServoControlPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *ServoControlTYPENAME = "ServoControl";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ServoControl_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ServoControl_g_tc_members[3]=
    {

        {
            (char *)"pan",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"tilt",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"frequency",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ServoControl_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ServoControl", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            ServoControl_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ServoControl*/

    if (is_initialized) {
        return &ServoControl_g_tc;
    }

    ServoControl_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ServoControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort_w_new;
    ServoControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort_w_new;
    ServoControl_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort_w_new;

    /* Initialize the values for member annotations. */
    ServoControl_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
    ServoControl_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    ServoControl_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    ServoControl_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
    ServoControl_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    ServoControl_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    ServoControl_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[2]._annotations._defaultValue._u.ushort_value = 0;
    ServoControl_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[2]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    ServoControl_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    ServoControl_g_tc_members[2]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    ServoControl_g_tc._data._sampleAccessInfo =
    ServoControl_get_sample_access_info();
    ServoControl_g_tc._data._typePlugin =
    ServoControl_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ServoControl_g_tc;
}

#define TSeq ServoControlSeq
#define T ServoControl
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ServoControl_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ServoControl_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ServoControlSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ServoControlSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ServoControl_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ServoControl_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    ServoControl *sample;

    static RTIXCdrMemberAccessInfo ServoControl_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ServoControl_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ServoControl_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ServoControl);
    if (sample == NULL) {
        return NULL;
    }

    ServoControl_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->pan - (char *)sample);

    ServoControl_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->tilt - (char *)sample);

    ServoControl_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->frequency - (char *)sample);

    ServoControl_g_sampleAccessInfo.memberAccessInfos = 
    ServoControl_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ServoControl);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ServoControl_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ServoControl_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ServoControl_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ServoControl_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ServoControl_get_member_value_pointer;

    ServoControl_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ServoControl_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ServoControl_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ServoControl_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ServoControl_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ServoControl_finalize_w_return,
        NULL
    };

    return &ServoControl_g_typePlugin;
}
#endif

RTIBool ServoControl_initialize(
    ServoControl* sample) {
    return ServoControl_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ServoControl_initialize_ex(
    ServoControl* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ServoControl_initialize_w_params(
        sample,&allocParams);

}

RTIBool ServoControl_initialize_w_params(
    ServoControl* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->pan = 0;

    sample->tilt = 0;

    sample->frequency = 0;

    return RTI_TRUE;
}

RTIBool ServoControl_finalize_w_return(
    ServoControl* sample)
{
    ServoControl_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void ServoControl_finalize(
    ServoControl* sample)
{

    ServoControl_finalize_ex(sample,RTI_TRUE);
}

void ServoControl_finalize_ex(
    ServoControl* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ServoControl_finalize_w_params(
        sample,&deallocParams);
}

void ServoControl_finalize_w_params(
    ServoControl* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void ServoControl_finalize_optional_members(
    ServoControl* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ServoControl_copy(
    ServoControl* dst,
    const ServoControl* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyUnsignedShort (
            &dst->pan, &src->pan)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedShort (
            &dst->tilt, &src->tilt)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedShort (
            &dst->frequency, &src->frequency)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ServoControl' sequence class.
*/
#define T ServoControl
#define TSeq ServoControlSeq

#define T_initialize_w_params ServoControl_initialize_w_params

#define T_finalize_w_params   ServoControl_finalize_w_params
#define T_copy       ServoControl_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<ServoControl>::get() 
        {
            return (const RTIXCdrTypeCode *) ServoControl_get_typecode();
        }

    } 
}
#endif
