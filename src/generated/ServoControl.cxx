

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

#include <new>

/* ========================================================================= */
const char *ServoControlTYPENAME = "ServoControl";

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
            NULL/* Ignored */
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
            NULL/* Ignored */
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
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode ServoControl_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ServoControl", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            ServoControl_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for ServoControl*/

    if (is_initialized) {
        return &ServoControl_g_tc;
    }

    ServoControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    ServoControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    ServoControl_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    is_initialized = RTI_TRUE;

    return &ServoControl_g_tc;
}

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

    if (!RTICdrType_initUnsignedShort(&sample->pan)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initUnsignedShort(&sample->tilt)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initUnsignedShort(&sample->frequency)) {
        return RTI_FALSE;
    }

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

    } catch (std::bad_alloc&) {
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

