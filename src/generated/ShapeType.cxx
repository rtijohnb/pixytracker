

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen".
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

#include "ShapeType.h"

#include <new>

/* ========================================================================= */
const char *ShapeFillKindTYPENAME = "ShapeFillKind";

DDS_TypeCode* ShapeFillKind_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ShapeFillKind_g_tc_members[4]=
    {

        {
            (char *)"SOLID_FILL",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            SOLID_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"TRANSPARENT_FILL",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            TRANSPARENT_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"HORIZONTAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            HORIZONTAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"VERTICAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            VERTICAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode ShapeFillKind_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeFillKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ShapeFillKind_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for ShapeFillKind*/

    if (is_initialized) {
        return &ShapeFillKind_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &ShapeFillKind_g_tc;
}

RTIBool ShapeFillKind_initialize(
    ShapeFillKind* sample) {
    *sample = SOLID_FILL;
    return RTI_TRUE;
}

RTIBool ShapeFillKind_initialize_ex(
    ShapeFillKind* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeFillKind_initialize_w_params(
        sample,&allocParams);

}

RTIBool ShapeFillKind_initialize_w_params(
    ShapeFillKind* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = SOLID_FILL;
    return RTI_TRUE;
}

void ShapeFillKind_finalize(
    ShapeFillKind* sample)
{

    if (sample==NULL) {
        return;
    }
}

void ShapeFillKind_finalize_ex(
    ShapeFillKind* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeFillKind_finalize_w_params(
        sample,&deallocParams);
}

void ShapeFillKind_finalize_w_params(
    ShapeFillKind* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void ShapeFillKind_finalize_optional_members(
    ShapeFillKind* sample, RTIBool deletePointers)
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

RTIBool ShapeFillKind_copy(
    ShapeFillKind* dst,
    const ShapeFillKind* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeFillKind' sequence class.
*/
#define T ShapeFillKind
#define TSeq ShapeFillKindSeq

#define T_initialize_w_params ShapeFillKind_initialize_w_params

#define T_finalize_w_params   ShapeFillKind_finalize_w_params
#define T_copy       ShapeFillKind_copy

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

/* ========================================================================= */
const char *ShapeTypeTYPENAME = "ShapeType";

DDS_TypeCode* ShapeType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode ShapeType_g_tc_color_string = DDS_INITIALIZE_STRING_TYPECODE((128));
    static DDS_TypeCode_Member ShapeType_g_tc_members[4]=
    {

        {
            (char *)"color",/* Member name */
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
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"x",/* Member name */
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
            (char *)"y",/* Member name */
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
        }, 
        {
            (char *)"shapesize",/* Member name */
            {
                3,/* Representation ID */          
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

    static DDS_TypeCode ShapeType_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeType", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ShapeType_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for ShapeType*/

    if (is_initialized) {
        return &ShapeType_g_tc;
    }

    ShapeType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ShapeType_g_tc_color_string;

    ShapeType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    ShapeType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    ShapeType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &ShapeType_g_tc;
}

RTIBool ShapeType_initialize(
    ShapeType* sample) {
    return ShapeType_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ShapeType_initialize_ex(
    ShapeType* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeType_initialize_w_params(
        sample,&allocParams);

}

RTIBool ShapeType_initialize_w_params(
    ShapeType* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->color= DDS_String_alloc ((128));
        if (sample->color == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->color!= NULL) { 
            sample->color[0] = '\0';
        }
    }

    if (!RTICdrType_initLong(&sample->x)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->y)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->shapesize)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void ShapeType_finalize(
    ShapeType* sample)
{

    ShapeType_finalize_ex(sample,RTI_TRUE);
}

void ShapeType_finalize_ex(
    ShapeType* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeType_finalize_w_params(
        sample,&deallocParams);
}

void ShapeType_finalize_w_params(
    ShapeType* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->color != NULL) {
        DDS_String_free(sample->color);
        sample->color=NULL;

    }

}

void ShapeType_finalize_optional_members(
    ShapeType* sample, RTIBool deletePointers)
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

RTIBool ShapeType_copy(
    ShapeType* dst,
    const ShapeType* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->color, src->color, 
            (128) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->x, &src->x)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->y, &src->y)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->shapesize, &src->shapesize)) { 
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
* Configure and implement 'ShapeType' sequence class.
*/
#define T ShapeType
#define TSeq ShapeTypeSeq

#define T_initialize_w_params ShapeType_initialize_w_params

#define T_finalize_w_params   ShapeType_finalize_w_params
#define T_copy       ShapeType_copy

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

/* ========================================================================= */
const char *ShapeTypeExtendedTYPENAME = "ShapeTypeExtended";

DDS_TypeCode* ShapeTypeExtended_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ShapeTypeExtended_g_tc_members[2]=
    {

        {
            (char *)"fillKind",/* Member name */
            {
                4,/* Representation ID */          
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
            (char *)"angle",/* Member name */
            {
                5,/* Representation ID */          
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

    static DDS_TypeCode ShapeTypeExtended_g_tc =
    {{
            DDS_TK_VALUE,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeTypeExtended", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            ShapeTypeExtended_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for ShapeTypeExtended*/

    if (is_initialized) {
        return &ShapeTypeExtended_g_tc;
    }

    ShapeTypeExtended_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ShapeFillKind_get_typecode();

    ShapeTypeExtended_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    ShapeTypeExtended_g_tc._data._typeCode = (RTICdrTypeCode *)ShapeType_get_typecode(); /* Base class */

    is_initialized = RTI_TRUE;

    return &ShapeTypeExtended_g_tc;
}

RTIBool ShapeTypeExtended_initialize(
    ShapeTypeExtended* sample) {
    return ShapeTypeExtended_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ShapeTypeExtended_initialize_ex(
    ShapeTypeExtended* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeTypeExtended_initialize_w_params(
        sample,&allocParams);

}

RTIBool ShapeTypeExtended_initialize_w_params(
    ShapeTypeExtended* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    if (!ShapeType_initialize_w_params((ShapeType*)sample,allocParams)) {
        return RTI_FALSE;
    }

    if (!ShapeFillKind_initialize_w_params(&sample->fillKind,
    allocParams)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->angle)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void ShapeTypeExtended_finalize(
    ShapeTypeExtended* sample)
{

    ShapeTypeExtended_finalize_ex(sample,RTI_TRUE);
}

void ShapeTypeExtended_finalize_ex(
    ShapeTypeExtended* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeTypeExtended_finalize_w_params(
        sample,&deallocParams);
}

void ShapeTypeExtended_finalize_w_params(
    ShapeTypeExtended* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }
    ShapeType_finalize_w_params((ShapeType*)sample,deallocParams);

    ShapeFillKind_finalize_w_params(&sample->fillKind,deallocParams);

}

void ShapeTypeExtended_finalize_optional_members(
    ShapeTypeExtended* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    ShapeType_finalize_optional_members((ShapeType*)sample,deletePointers);

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    ShapeFillKind_finalize_optional_members(&sample->fillKind, deallocParams->delete_pointers);
}

RTIBool ShapeTypeExtended_copy(
    ShapeTypeExtended* dst,
    const ShapeTypeExtended* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if(!ShapeType_copy((ShapeType*)dst,(const ShapeType*)src)) {
            return RTI_FALSE;
        }

        if (!ShapeFillKind_copy(
            &dst->fillKind,(const ShapeFillKind*)&src->fillKind)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyFloat (
            &dst->angle, &src->angle)) { 
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
* Configure and implement 'ShapeTypeExtended' sequence class.
*/
#define T ShapeTypeExtended
#define TSeq ShapeTypeExtendedSeq

#define T_initialize_w_params ShapeTypeExtended_initialize_w_params

#define T_finalize_w_params   ShapeTypeExtended_finalize_w_params
#define T_copy       ShapeTypeExtended_copy

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

/* ========================================================================= */
const char *PixyCamConfigTYPENAME = "PixyCamConfig";

DDS_TypeCode* PixyCamConfig_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode PixyCamConfig_g_tc_profileEnabled_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,7, NULL,NULL);
    static DDS_TypeCode_Member PixyCamConfig_g_tc_members[1]=
    {

        {
            (char *)"profileEnabled",/* Member name */
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
        }
    };

    static DDS_TypeCode PixyCamConfig_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"PixyCamConfig", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            PixyCamConfig_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for PixyCamConfig*/

    if (is_initialized) {
        return &PixyCamConfig_g_tc;
    }

    PixyCamConfig_g_tc_profileEnabled_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_boolean;

    PixyCamConfig_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& PixyCamConfig_g_tc_profileEnabled_array;

    is_initialized = RTI_TRUE;

    return &PixyCamConfig_g_tc;
}

RTIBool PixyCamConfig_initialize(
    PixyCamConfig* sample) {
    return PixyCamConfig_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool PixyCamConfig_initialize_ex(
    PixyCamConfig* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PixyCamConfig_initialize_w_params(
        sample,&allocParams);

}

RTIBool PixyCamConfig_initialize_w_params(
    PixyCamConfig* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initArray(
        sample->profileEnabled, (7), RTI_CDR_BOOLEAN_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void PixyCamConfig_finalize(
    PixyCamConfig* sample)
{

    PixyCamConfig_finalize_ex(sample,RTI_TRUE);
}

void PixyCamConfig_finalize_ex(
    PixyCamConfig* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PixyCamConfig_finalize_w_params(
        sample,&deallocParams);
}

void PixyCamConfig_finalize_w_params(
    PixyCamConfig* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void PixyCamConfig_finalize_optional_members(
    PixyCamConfig* sample, RTIBool deletePointers)
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

RTIBool PixyCamConfig_copy(
    PixyCamConfig* dst,
    const PixyCamConfig* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyArray(
            dst->profileEnabled ,src->profileEnabled,(7), RTI_CDR_BOOLEAN_SIZE)) {
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
* Configure and implement 'PixyCamConfig' sequence class.
*/
#define T PixyCamConfig
#define TSeq PixyCamConfigSeq

#define T_initialize_w_params PixyCamConfig_initialize_w_params

#define T_finalize_w_params   PixyCamConfig_finalize_w_params
#define T_copy       PixyCamConfig_copy

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

