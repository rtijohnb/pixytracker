
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>

#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include <new>

#include "ShapeTypePlugin.h"

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

RTIBool 
ShapeFillKindPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ShapeFillKind *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    const char *METHOD_NAME = "ShapeFillKindPlugin_serialize";

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (*sample != SOLID_FILL && *sample != TRANSPARENT_FILL && *sample != HORIZONTAL_HATCH_FILL && *sample != VERTICAL_HATCH_FILL){
            RTICdrLog_exception(
                METHOD_NAME, 
                &RTI_CDR_LOG_SERIALIZE_INVALID_ENUMERATOR_ds, 
                *sample, 
                "ShapeFillKind");
            return RTI_FALSE;       
        }

        if (!RTICdrStream_serializeEnum(stream, sample))
        {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool 
ShapeFillKindPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeFillKind *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;
    DDS_Enum enum_tmp;
    const char *METHOD_NAME = "ShapeFillKindPlugin_deserialize_sample";

    try {

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */
        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if(deserialize_sample) {

            if (!RTICdrStream_deserializeEnum(stream, &enum_tmp))
            {
                return RTI_FALSE;
            }
            switch (enum_tmp) {
                case SOLID_FILL:
                *sample=SOLID_FILL;
                break;
                case TRANSPARENT_FILL:
                *sample=TRANSPARENT_FILL;
                break;
                case HORIZONTAL_HATCH_FILL:
                *sample=HORIZONTAL_HATCH_FILL;
                break;
                case VERTICAL_HATCH_FILL:
                *sample=VERTICAL_HATCH_FILL;
                break;
                default:
                {
                    struct PRESTypePluginDefaultEndpointData * epd =
                    (struct PRESTypePluginDefaultEndpointData *)
                    endpoint_data;
                    const struct PRESTypePluginSampleAssignabilityProperty * ap =
                    PRESTypePluginDefaultEndpointData_getAssignabilityProperty(epd);

                    if (ap->acceptUnknownEnumValue) {
                        ShapeFillKind_initialize(sample);
                    } else {
                        stream->_xTypesState.unassignable = RTI_TRUE;
                        RTICdrLog_exception(
                            METHOD_NAME, 
                            &RTI_CDR_LOG_DESERIALIZE_INVALID_ENUMERATOR_ds, 
                            enum_tmp, 
                            "ShapeFillKind");
                        return RTI_FALSE;
                    }
                }
            }

        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool ShapeFillKindPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }
    }

    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
ShapeFillKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,
        NULL,
        include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

unsigned int ShapeFillKindPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ShapeFillKindPlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
ShapeFillKindPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ShapeFillKind * sample) 
{

    unsigned int initial_alignment = current_alignment;

    if (sample==NULL) {
        return 0;
    }

    current_alignment += ShapeFillKindPlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id,
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data,
            current_alignment));

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

RTIBool 
ShapeFillKindPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ShapeFillKind *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    return  ShapeFillKindPlugin_serialize(
        endpoint_data, sample, stream, 
        serialize_encapsulation, encapsulation_id, 
        serialize_key, endpoint_plugin_qos);

}

RTIBool ShapeFillKindPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeFillKind *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {

        return  ShapeFillKindPlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

unsigned int
ShapeFillKindPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    current_alignment +=  ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

RTIBool 
ShapeFillKindPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeFillKind *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{

    return  ShapeFillKindPlugin_deserialize_sample(
        endpoint_data, sample, stream, deserialize_encapsulation, 
        deserialize_key, endpoint_plugin_qos);

}

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

void ShapeFillKindPluginSupport_print_data(
    const ShapeFillKind *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "ShapeFillKind", indent_level + 1);
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */

/* ----------------------------------------------------------------------------
*  Type ShapeType
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

ShapeType*
ShapeTypePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    ShapeType *sample = NULL;

    sample = new (std::nothrow) ShapeType ;
    if (sample == NULL) {
        return NULL;
    }

    if (!ShapeType_initialize_w_params(sample,alloc_params)) {
        delete  sample;
        sample=NULL;
    }
    return sample; 
} 

ShapeType *
ShapeTypePluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    ShapeType *sample = NULL;

    sample = new (std::nothrow) ShapeType ;

    if(sample == NULL) {
        return NULL;
    }

    if (!ShapeType_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        delete  sample;
        sample=NULL;
    }

    return sample; 
}

ShapeType *
ShapeTypePluginSupport_create_data(void)
{
    return ShapeTypePluginSupport_create_data_ex(RTI_TRUE);
}

void 
ShapeTypePluginSupport_destroy_data_w_params(
    ShapeType *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    ShapeType_finalize_w_params(sample,dealloc_params);

    delete  sample;
    sample=NULL;
}

void 
ShapeTypePluginSupport_destroy_data_ex(
    ShapeType *sample,RTIBool deallocate_pointers) {

    ShapeType_finalize_ex(sample,deallocate_pointers);

    delete  sample;
    sample=NULL;
}

void 
ShapeTypePluginSupport_destroy_data(
    ShapeType *sample) {

    ShapeTypePluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
ShapeTypePluginSupport_copy_data(
    ShapeType *dst,
    const ShapeType *src)
{
    return ShapeType_copy(dst,(const ShapeType*) src);
}

void 
ShapeTypePluginSupport_print_data(
    const ShapeType *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

    if (sample->color==NULL) {
        RTICdrType_printString(
            NULL,"color", indent_level + 1);
    } else {
        RTICdrType_printString(
            sample->color,"color", indent_level + 1);    
    }

    RTICdrType_printLong(
        &sample->x, "x", indent_level + 1);    

    RTICdrType_printLong(
        &sample->y, "y", indent_level + 1);    

    RTICdrType_printLong(
        &sample->shapesize, "shapesize", indent_level + 1);    

}
ShapeType *
ShapeTypePluginSupport_create_key_ex(RTIBool allocate_pointers){
    ShapeType *key = NULL;

    key = new (std::nothrow) ShapeTypeKeyHolder ;

    ShapeType_initialize_ex(key,allocate_pointers, RTI_TRUE);

    return key;
}

ShapeType *
ShapeTypePluginSupport_create_key(void)
{
    return  ShapeTypePluginSupport_create_key_ex(RTI_TRUE);
}

void 
ShapeTypePluginSupport_destroy_key_ex(
    ShapeTypeKeyHolder *key,RTIBool deallocate_pointers)
{
    ShapeType_finalize_ex(key,deallocate_pointers);

    delete  key;
    key=NULL;

}

void 
ShapeTypePluginSupport_destroy_key(
    ShapeTypeKeyHolder *key) {

    ShapeTypePluginSupport_destroy_key_ex(key,RTI_TRUE);

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
ShapeTypePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
ShapeTypePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
ShapeTypePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        ShapeTypePluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        ShapeTypePluginSupport_destroy_data,
        (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
        ShapeTypePluginSupport_create_key ,            
        (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
        ShapeTypePluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    } 
    serializedKeyMaxSize =  ShapeTypePlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

    if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
        epd,endpoint_info,serializedKeyMaxSize))  
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = ShapeTypePlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            ShapeTypePlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ShapeTypePlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
ShapeTypePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
ShapeTypePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType *sample,
    void *handle)
{

    ShapeType_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
ShapeTypePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType *dst,
    const ShapeType *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ShapeTypePluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
ShapeTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
ShapeTypePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ShapeType *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeString(
            stream, sample->color, (128) + 1)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeLong(
            stream, &sample->x)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeLong(
            stream, &sample->y)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeLong(
            stream, &sample->shapesize)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

RTIBool 
ShapeTypePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;

    RTIBool done = RTI_FALSE;

    try {

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */
        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if(deserialize_sample) {

            ShapeType_initialize_ex(sample, RTI_FALSE, RTI_FALSE);

            if (!RTICdrStream_deserializeStringEx(
                stream,&sample->color, (128) + 1, RTI_FALSE)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeLong(
                stream, &sample->x)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeLong(
                stream, &sample->y)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeLong(
                stream, &sample->shapesize)) {
                goto fin; 
            }
        }

        done = RTI_TRUE;
      fin:
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool
ShapeTypePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ShapeType *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    ShapeTypePlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 0);

    if (buffer == NULL) {
        *length = 
        ShapeTypePlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTICdrEncapsulation_getNativeCdrEncapsulationId(),
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = ShapeTypePlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
}

RTIBool
ShapeTypePlugin_deserialize_from_cdr_buffer(
    ShapeType *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    ShapeType_finalize_optional_members(sample, RTI_TRUE);
    return ShapeTypePlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

DDS_ReturnCode_t
ShapeTypePlugin_data_to_string(
    const ShapeType *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (!ShapeTypePlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!ShapeTypePlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    data = DDS_DynamicData_new(
        ShapeType_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}

RTIBool 
ShapeTypePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    const char *METHOD_NAME = "ShapeTypePlugin_deserialize";
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= ShapeTypePlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    if (!result && stream->_xTypesState.unassignable ) {

        RTICdrLog_exception(
            METHOD_NAME, 
            &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
            "ShapeType");

    }

    return result;

}

RTIBool ShapeTypePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipString (stream, (128)+1)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
ShapeTypePlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (128)+1);

    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
ShapeTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = ShapeTypePlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
ShapeTypePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
ShapeTypePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ShapeType * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;
    struct PRESTypePluginDefaultEndpointData epd;   

    if (sample==NULL) {
        return 0;
    }
    if (endpoint_data == NULL) {
        endpoint_data = (PRESTypePluginEndpointData) &epd;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);        
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);
    }

    current_alignment += RTICdrType_getStringSerializedSize(
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data, current_alignment), sample->color);

    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data, current_alignment));

    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data, current_alignment));

    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data, current_alignment));

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
ShapeTypePlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool 
ShapeTypePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ShapeType *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {

        if (!RTICdrStream_serializeString(
            stream, sample->color, (128) + 1)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool ShapeTypePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {

        char * position = NULL;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if (deserialize_key) {

            if (!RTICdrStream_deserializeStringEx(
                stream,&sample->color, (128) + 1, RTI_FALSE)) {
                return RTI_FALSE;
            }
        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool ShapeTypePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= ShapeTypePlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
ShapeTypePlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (128)+1);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
ShapeTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = ShapeTypePlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
ShapeTypePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!RTICdrStream_deserializeStringEx(
            stream,&sample->color, (128) + 1, RTI_FALSE)) {
            return RTI_FALSE;
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }

        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }

        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool 
ShapeTypePlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeKeyHolder *dst, 
    const ShapeType *src)
{

    if (endpoint_data) {} /* To avoid warnings */   

    if (!RTICdrType_copyStringEx (
        &dst->color, src->color, 
        (128) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
ShapeTypePlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ShapeType *dst, const
    ShapeTypeKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */   
    if (!RTICdrType_copyStringEx (
        &dst->color, src->color, 
        (128) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
ShapeTypePlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ShapeType *instance)
{
    struct RTICdrStream * md5Stream = NULL;
    struct RTICdrStreamState cdrState;
    char * buffer = NULL;

    RTICdrStreamState_init(&cdrState);
    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!ShapeTypePlugin_serialize_key(
        endpoint_data,
        instance,
        md5Stream, 
        RTI_FALSE, 
        RTI_CDR_ENCAPSULATION_ID_CDR_BE, 
        RTI_TRUE,
        NULL)) 
    {
        int size;

        RTICdrStream_pushState(md5Stream, &cdrState, -1);

        size = (int)ShapeTypePlugin_get_serialized_sample_size(
            endpoint_data,
            RTI_FALSE,
            RTI_CDR_ENCAPSULATION_ID_CDR_BE,
            0,
            instance);

        if (size <= RTICdrStream_getBufferLength(md5Stream)) {
            RTICdrStream_popState(md5Stream, &cdrState);        
            return RTI_FALSE;
        }   

        RTIOsapiHeap_allocateBuffer(&buffer,size,0);

        if (buffer == NULL) {
            RTICdrStream_popState(md5Stream, &cdrState);
            return RTI_FALSE;
        }

        RTICdrStream_set(md5Stream, buffer, size);
        RTIOsapiMemory_zero(
            RTICdrStream_getBuffer(md5Stream),
            RTICdrStream_getBufferLength(md5Stream));
        RTICdrStream_resetPosition(md5Stream);
        RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);
        if (!ShapeTypePlugin_serialize_key(
            endpoint_data,
            instance,
            md5Stream, 
            RTI_FALSE, 
            RTI_CDR_ENCAPSULATION_ID_CDR_BE, 
            RTI_TRUE,
            NULL)) 
        {
            RTICdrStream_popState(md5Stream, &cdrState);
            RTIOsapiHeap_freeBuffer(buffer);
            return RTI_FALSE;
        }        
    }   

    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > 
    (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH) ||
    PRESTypePluginDefaultEndpointData_forceMD5KeyHash(endpoint_data)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;

    if (buffer != NULL) {
        RTICdrStream_popState(md5Stream, &cdrState);
        RTIOsapiHeap_freeBuffer(buffer);
    }

    return RTI_TRUE;
}

RTIBool 
ShapeTypePlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;
    ShapeType * sample=NULL;

    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }

    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    sample = (ShapeType *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrStream_deserializeStringEx(
        stream,&sample->color, (128) + 1, RTI_FALSE)) {
        return RTI_FALSE;
    }
    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    } 

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    if (!ShapeTypePlugin_instance_to_keyhash(
        endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *ShapeTypePlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    ShapeTypePlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    ShapeTypePlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    ShapeTypePlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    ShapeTypePlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    ShapeTypePlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    ShapeTypePlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    ShapeTypePlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    ShapeTypePlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    ShapeTypePlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    ShapeTypePlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    ShapeTypePlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    ShapeTypePlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    ShapeTypePlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    ShapeTypePlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    ShapeTypePlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    ShapeTypePlugin_serialize_key;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    ShapeTypePlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    ShapeTypePlugin_deserialize_key_sample;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    ShapeTypePlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    ShapeTypePlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    ShapeTypePlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    ShapeTypePlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    ShapeTypePlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    ShapeTypePlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    plugin->typeCode =  (struct RTICdrTypeCode *)ShapeType_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    ShapeTypePlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    ShapeTypePlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    ShapeTypePlugin_get_serialized_sample_size;

    plugin->endpointTypeName = ShapeTypeTYPENAME;

    return plugin;
}

void
ShapeTypePlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type ShapeTypeExtended
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

ShapeTypeExtended*
ShapeTypeExtendedPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    ShapeTypeExtended *sample = NULL;

    sample = new (std::nothrow) ShapeTypeExtended ;
    if (sample == NULL) {
        return NULL;
    }

    if (!ShapeTypeExtended_initialize_w_params(sample,alloc_params)) {
        delete  sample;
        sample=NULL;
    }
    return sample; 
} 

ShapeTypeExtended *
ShapeTypeExtendedPluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    ShapeTypeExtended *sample = NULL;

    sample = new (std::nothrow) ShapeTypeExtended ;

    if(sample == NULL) {
        return NULL;
    }

    if (!ShapeTypeExtended_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        delete  sample;
        sample=NULL;
    }

    return sample; 
}

ShapeTypeExtended *
ShapeTypeExtendedPluginSupport_create_data(void)
{
    return ShapeTypeExtendedPluginSupport_create_data_ex(RTI_TRUE);
}

void 
ShapeTypeExtendedPluginSupport_destroy_data_w_params(
    ShapeTypeExtended *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    ShapeTypeExtended_finalize_w_params(sample,dealloc_params);

    delete  sample;
    sample=NULL;
}

void 
ShapeTypeExtendedPluginSupport_destroy_data_ex(
    ShapeTypeExtended *sample,RTIBool deallocate_pointers) {

    ShapeTypeExtended_finalize_ex(sample,deallocate_pointers);

    delete  sample;
    sample=NULL;
}

void 
ShapeTypeExtendedPluginSupport_destroy_data(
    ShapeTypeExtended *sample) {

    ShapeTypeExtendedPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
ShapeTypeExtendedPluginSupport_copy_data(
    ShapeTypeExtended *dst,
    const ShapeTypeExtended *src)
{
    return ShapeTypeExtended_copy(dst,(const ShapeTypeExtended*) src);
}

void 
ShapeTypeExtendedPluginSupport_print_data(
    const ShapeTypeExtended *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

    ShapeTypePluginSupport_print_data((const ShapeType*)sample,"",indent_level);

    ShapeFillKindPluginSupport_print_data(
        (const ShapeFillKind*) &sample->fillKind, "fillKind", indent_level + 1);

    RTICdrType_printFloat(
        &sample->angle, "angle", indent_level + 1);    

}
ShapeTypeExtended *
ShapeTypeExtendedPluginSupport_create_key_ex(RTIBool allocate_pointers){
    ShapeTypeExtended *key = NULL;

    key = new (std::nothrow) ShapeTypeExtendedKeyHolder ;

    ShapeTypeExtended_initialize_ex(key,allocate_pointers, RTI_TRUE);

    return key;
}

ShapeTypeExtended *
ShapeTypeExtendedPluginSupport_create_key(void)
{
    return  ShapeTypeExtendedPluginSupport_create_key_ex(RTI_TRUE);
}

void 
ShapeTypeExtendedPluginSupport_destroy_key_ex(
    ShapeTypeExtendedKeyHolder *key,RTIBool deallocate_pointers)
{
    ShapeTypeExtended_finalize_ex(key,deallocate_pointers);

    delete  key;
    key=NULL;

}

void 
ShapeTypeExtendedPluginSupport_destroy_key(
    ShapeTypeExtendedKeyHolder *key) {

    ShapeTypeExtendedPluginSupport_destroy_key_ex(key,RTI_TRUE);

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
ShapeTypeExtendedPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
ShapeTypeExtendedPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
ShapeTypeExtendedPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        ShapeTypeExtendedPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        ShapeTypeExtendedPluginSupport_destroy_data,
        (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
        ShapeTypeExtendedPluginSupport_create_key ,            
        (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
        ShapeTypeExtendedPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    } 
    serializedKeyMaxSize =  ShapeTypeExtendedPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

    if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
        epd,endpoint_info,serializedKeyMaxSize))  
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            ShapeTypeExtendedPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ShapeTypeExtendedPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
ShapeTypeExtendedPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
ShapeTypeExtendedPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended *sample,
    void *handle)
{

    ShapeTypeExtended_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
ShapeTypeExtendedPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended *dst,
    const ShapeTypeExtended *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ShapeTypeExtendedPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
ShapeTypeExtendedPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (!ShapeTypePlugin_serialize(endpoint_data,
        (const ShapeType*)sample,stream,RTI_FALSE,encapsulation_id,
        RTI_TRUE,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

        if(!ShapeFillKindPlugin_serialize(
            endpoint_data,
            (const ShapeFillKind*) &sample->fillKind,
            stream,
            RTI_FALSE, encapsulation_id,
            RTI_TRUE,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeFloat(
            stream, &sample->angle)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

RTIBool 
ShapeTypeExtendedPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;

    RTIBool done = RTI_FALSE;

    try {

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if(deserialize_sample) {

            ShapeTypeExtended_initialize_ex(sample, RTI_FALSE, RTI_FALSE);
            if (!ShapeTypePlugin_deserialize_sample(endpoint_data,
            (ShapeType *)sample,stream,RTI_FALSE,RTI_TRUE,
            endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

            if(!ShapeFillKindPlugin_deserialize_sample(
                endpoint_data,
                &sample->fillKind,
                stream,
                RTI_FALSE, RTI_TRUE,
                endpoint_plugin_qos)) {
                goto fin; 
            }
            if (!RTICdrStream_deserializeFloat(
                stream, &sample->angle)) {
                goto fin; 
            }
        }

        done = RTI_TRUE;
      fin:
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool
ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ShapeTypeExtended *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 0);

    if (buffer == NULL) {
        *length = 
        ShapeTypeExtendedPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTICdrEncapsulation_getNativeCdrEncapsulationId(),
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = ShapeTypeExtendedPlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
}

RTIBool
ShapeTypeExtendedPlugin_deserialize_from_cdr_buffer(
    ShapeTypeExtended *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    ShapeTypeExtended_finalize_optional_members(sample, RTI_TRUE);
    return ShapeTypeExtendedPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

DDS_ReturnCode_t
ShapeTypeExtendedPlugin_data_to_string(
    const ShapeTypeExtended *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (!ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    data = DDS_DynamicData_new(
        ShapeTypeExtended_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}

RTIBool 
ShapeTypeExtendedPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    const char *METHOD_NAME = "ShapeTypeExtendedPlugin_deserialize";
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= ShapeTypeExtendedPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    if (!result && stream->_xTypesState.unassignable ) {

        RTICdrLog_exception(
            METHOD_NAME, 
            &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
            "ShapeTypeExtended");

    }

    return result;

}

RTIBool ShapeTypeExtendedPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!ShapeTypePlugin_skip(endpoint_data,
        stream,RTI_FALSE,RTI_TRUE,
        endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

        if (!ShapeFillKindPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            goto fin; 
        }
        if (!RTICdrStream_skipFloat (stream)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
ShapeTypeExtendedPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += ShapeTypePlugin_get_serialized_sample_max_size_ex(
        endpoint_data,overflow,RTI_FALSE,encapsulation_id,current_alignment);

    current_alignment +=ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, RTI_FALSE,encapsulation_id,current_alignment);

    current_alignment +=RTICdrType_getFloatMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = ShapeTypeExtendedPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
ShapeTypeExtendedPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += ShapeTypePlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);

    current_alignment +=ShapeFillKindPlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
    current_alignment +=RTICdrType_getFloatMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
ShapeTypeExtendedPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ShapeTypeExtended * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;
    struct PRESTypePluginDefaultEndpointData epd;   

    if (endpoint_data == NULL) {
        endpoint_data = (PRESTypePluginEndpointData) &epd;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);        
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);
    }

    current_alignment += ShapeTypePlugin_get_serialized_sample_size(endpoint_data,RTI_FALSE,encapsulation_id,current_alignment,(const ShapeType*)sample);   

    current_alignment += ShapeFillKindPlugin_get_serialized_sample_size(
        endpoint_data,RTI_FALSE, encapsulation_id,
        current_alignment, (const ShapeFillKind*) &sample->fillKind);

    current_alignment += RTICdrType_getFloatMaxSizeSerialized(
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data, current_alignment));

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
ShapeTypeExtendedPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool 
ShapeTypeExtendedPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {

        if (!ShapeTypePlugin_serialize_key(endpoint_data, 
        (const ShapeType*)sample, stream, RTI_FALSE, 
        encapsulation_id,RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool ShapeTypeExtendedPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {

        char * position = NULL;

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if (deserialize_key) {

            if (!ShapeTypePlugin_deserialize_key_sample(endpoint_data,
            (ShapeType*)sample,stream,RTI_FALSE,RTI_TRUE,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }    

        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool ShapeTypeExtendedPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= ShapeTypeExtendedPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
ShapeTypeExtendedPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += ShapeTypePlugin_get_serialized_key_max_size_ex(
        endpoint_data,
        overflow,
        RTI_FALSE, encapsulation_id,
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
ShapeTypeExtendedPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = ShapeTypeExtendedPlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
ShapeTypeExtendedPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!ShapeTypePlugin_serialized_sample_to_key(endpoint_data,
        (ShapeType *)sample,
        stream, RTI_FALSE, RTI_TRUE,
        endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

        if (!ShapeFillKindPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            goto fin; 
        }

        if (!RTICdrStream_skipFloat (stream)) {
            goto fin; 
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool 
ShapeTypeExtendedPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtendedKeyHolder *dst, 
    const ShapeTypeExtended *src)
{

    if (!ShapeTypePlugin_instance_to_key(endpoint_data,(ShapeType *)dst,(const ShapeType*)src)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTIBool 
ShapeTypeExtendedPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ShapeTypeExtended *dst, const
    ShapeTypeExtendedKeyHolder *src)
{

    if (!ShapeTypePlugin_key_to_instance(endpoint_data,(ShapeType*)dst,(const ShapeType*)src)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
ShapeTypeExtendedPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ShapeTypeExtended *instance)
{
    struct RTICdrStream * md5Stream = NULL;
    struct RTICdrStreamState cdrState;
    char * buffer = NULL;

    RTICdrStreamState_init(&cdrState);
    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!ShapeTypeExtendedPlugin_serialize_key(
        endpoint_data,
        instance,
        md5Stream, 
        RTI_FALSE, 
        RTI_CDR_ENCAPSULATION_ID_CDR_BE, 
        RTI_TRUE,
        NULL)) 
    {
        int size;

        RTICdrStream_pushState(md5Stream, &cdrState, -1);

        size = (int)ShapeTypeExtendedPlugin_get_serialized_sample_size(
            endpoint_data,
            RTI_FALSE,
            RTI_CDR_ENCAPSULATION_ID_CDR_BE,
            0,
            instance);

        if (size <= RTICdrStream_getBufferLength(md5Stream)) {
            RTICdrStream_popState(md5Stream, &cdrState);        
            return RTI_FALSE;
        }   

        RTIOsapiHeap_allocateBuffer(&buffer,size,0);

        if (buffer == NULL) {
            RTICdrStream_popState(md5Stream, &cdrState);
            return RTI_FALSE;
        }

        RTICdrStream_set(md5Stream, buffer, size);
        RTIOsapiMemory_zero(
            RTICdrStream_getBuffer(md5Stream),
            RTICdrStream_getBufferLength(md5Stream));
        RTICdrStream_resetPosition(md5Stream);
        RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);
        if (!ShapeTypeExtendedPlugin_serialize_key(
            endpoint_data,
            instance,
            md5Stream, 
            RTI_FALSE, 
            RTI_CDR_ENCAPSULATION_ID_CDR_BE, 
            RTI_TRUE,
            NULL)) 
        {
            RTICdrStream_popState(md5Stream, &cdrState);
            RTIOsapiHeap_freeBuffer(buffer);
            return RTI_FALSE;
        }        
    }   

    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > 
    (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH) ||
    PRESTypePluginDefaultEndpointData_forceMD5KeyHash(endpoint_data)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;

    if (buffer != NULL) {
        RTICdrStream_popState(md5Stream, &cdrState);
        RTIOsapiHeap_freeBuffer(buffer);
    }

    return RTI_TRUE;
}

RTIBool 
ShapeTypeExtendedPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;
    ShapeTypeExtended * sample=NULL;

    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }

    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    sample = (ShapeTypeExtended *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (!ShapeTypePlugin_serialized_sample_to_key(endpoint_data,
    (ShapeType *)sample,
    stream, RTI_FALSE, RTI_TRUE,
    endpoint_plugin_qos)) {
        return RTI_FALSE;
    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    } 

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    if (!ShapeTypeExtendedPlugin_instance_to_keyhash(
        endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *ShapeTypeExtendedPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    ShapeTypeExtendedPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    ShapeTypeExtendedPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    ShapeTypeExtendedPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    ShapeTypeExtendedPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    ShapeTypeExtendedPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    ShapeTypeExtendedPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    ShapeTypeExtendedPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    ShapeTypeExtendedPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    ShapeTypeExtendedPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    ShapeTypeExtendedPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    ShapeTypeExtendedPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    ShapeTypeExtendedPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    ShapeTypeExtendedPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    ShapeTypeExtendedPlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    ShapeTypeExtendedPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    ShapeTypeExtendedPlugin_serialize_key;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    ShapeTypeExtendedPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    ShapeTypeExtendedPlugin_deserialize_key_sample;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    ShapeTypeExtendedPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    ShapeTypeExtendedPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    ShapeTypeExtendedPlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    ShapeTypeExtendedPlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    ShapeTypeExtendedPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    ShapeTypeExtendedPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    plugin->typeCode =  (struct RTICdrTypeCode *)ShapeTypeExtended_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    ShapeTypeExtendedPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    ShapeTypeExtendedPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    ShapeTypeExtendedPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = ShapeTypeExtendedTYPENAME;

    return plugin;
}

void
ShapeTypeExtendedPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type PixyCamConfig
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

PixyCamConfig*
PixyCamConfigPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    PixyCamConfig *sample = NULL;

    sample = new (std::nothrow) PixyCamConfig ;
    if (sample == NULL) {
        return NULL;
    }

    if (!PixyCamConfig_initialize_w_params(sample,alloc_params)) {
        delete  sample;
        sample=NULL;
    }
    return sample; 
} 

PixyCamConfig *
PixyCamConfigPluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    PixyCamConfig *sample = NULL;

    sample = new (std::nothrow) PixyCamConfig ;

    if(sample == NULL) {
        return NULL;
    }

    if (!PixyCamConfig_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        delete  sample;
        sample=NULL;
    }

    return sample; 
}

PixyCamConfig *
PixyCamConfigPluginSupport_create_data(void)
{
    return PixyCamConfigPluginSupport_create_data_ex(RTI_TRUE);
}

void 
PixyCamConfigPluginSupport_destroy_data_w_params(
    PixyCamConfig *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    PixyCamConfig_finalize_w_params(sample,dealloc_params);

    delete  sample;
    sample=NULL;
}

void 
PixyCamConfigPluginSupport_destroy_data_ex(
    PixyCamConfig *sample,RTIBool deallocate_pointers) {

    PixyCamConfig_finalize_ex(sample,deallocate_pointers);

    delete  sample;
    sample=NULL;
}

void 
PixyCamConfigPluginSupport_destroy_data(
    PixyCamConfig *sample) {

    PixyCamConfigPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
PixyCamConfigPluginSupport_copy_data(
    PixyCamConfig *dst,
    const PixyCamConfig *src)
{
    return PixyCamConfig_copy(dst,(const PixyCamConfig*) src);
}

void 
PixyCamConfigPluginSupport_print_data(
    const PixyCamConfig *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printArray(
        sample->profileEnabled, (7), RTI_CDR_BOOLEAN_SIZE,
        (RTICdrTypePrintFunction)RTICdrType_printBoolean, 
        "profileEnabled", indent_level + 1);        

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
PixyCamConfigPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
PixyCamConfigPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
PixyCamConfigPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        PixyCamConfigPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        PixyCamConfigPluginSupport_destroy_data,
        NULL , NULL );

    if (epd == NULL) {
        return NULL;
    } 

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = PixyCamConfigPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            PixyCamConfigPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            PixyCamConfigPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
PixyCamConfigPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
PixyCamConfigPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig *sample,
    void *handle)
{

    PixyCamConfig_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
PixyCamConfigPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig *dst,
    const PixyCamConfig *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return PixyCamConfigPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
PixyCamConfigPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
PixyCamConfigPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const PixyCamConfig *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (!RTICdrStream_serializePrimitiveArray(
            stream, (void*) sample->profileEnabled, (7), RTI_CDR_BOOLEAN_TYPE)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

RTIBool 
PixyCamConfigPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;

    RTIBool done = RTI_FALSE;

    try {

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */
        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if(deserialize_sample) {

            PixyCamConfig_initialize_ex(sample, RTI_FALSE, RTI_FALSE);

            if (!RTICdrStream_deserializePrimitiveArray(
                stream, (void*) sample->profileEnabled, (7), RTI_CDR_BOOLEAN_TYPE)) {
                goto fin; 
            }

        }

        done = RTI_TRUE;
      fin:
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool
PixyCamConfigPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const PixyCamConfig *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    PixyCamConfigPlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 0);

    if (buffer == NULL) {
        *length = 
        PixyCamConfigPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTICdrEncapsulation_getNativeCdrEncapsulationId(),
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = PixyCamConfigPlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
}

RTIBool
PixyCamConfigPlugin_deserialize_from_cdr_buffer(
    PixyCamConfig *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    PixyCamConfig_finalize_optional_members(sample, RTI_TRUE);
    return PixyCamConfigPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

DDS_ReturnCode_t
PixyCamConfigPlugin_data_to_string(
    const PixyCamConfig *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (!PixyCamConfigPlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!PixyCamConfigPlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    data = DDS_DynamicData_new(
        PixyCamConfig_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}

RTIBool 
PixyCamConfigPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    const char *METHOD_NAME = "PixyCamConfigPlugin_deserialize";
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= PixyCamConfigPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    if (!result && stream->_xTypesState.unassignable ) {

        RTICdrLog_exception(
            METHOD_NAME, 
            &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
            "PixyCamConfig");

    }

    return result;

}

RTIBool PixyCamConfigPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipPrimitiveArray(
            stream, (7), RTI_CDR_BOOLEAN_TYPE)) {
            goto fin; 
        }      
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
PixyCamConfigPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (7),  RTI_CDR_BOOLEAN_TYPE);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
PixyCamConfigPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = PixyCamConfigPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
PixyCamConfigPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (7), RTI_CDR_BOOLEAN_TYPE);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
PixyCamConfigPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const PixyCamConfig * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;
    struct PRESTypePluginDefaultEndpointData epd;   

    if (sample==NULL) {
        return 0;
    }
    if (endpoint_data == NULL) {
        endpoint_data = (PRESTypePluginEndpointData) &epd;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);        
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);
    }

    current_alignment += RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        PRESTypePluginDefaultEndpointData_getAlignment(
            endpoint_data, current_alignment), 
            (7), RTI_CDR_BOOLEAN_TYPE);  

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
PixyCamConfigPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
PixyCamConfigPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const PixyCamConfig *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {

        if (!PixyCamConfigPlugin_serialize(
            endpoint_data,
            sample,
            stream,
            RTI_FALSE, encapsulation_id,
            RTI_TRUE,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool PixyCamConfigPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {

        char * position = NULL;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if (deserialize_key) {

            if (!PixyCamConfigPlugin_deserialize_sample(
                endpoint_data, sample, stream, 
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

RTIBool PixyCamConfigPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= PixyCamConfigPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
PixyCamConfigPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += PixyCamConfigPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow,RTI_FALSE, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
PixyCamConfigPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = PixyCamConfigPlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
PixyCamConfigPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    PixyCamConfig *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!PixyCamConfigPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *PixyCamConfigPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    PixyCamConfigPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    PixyCamConfigPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    PixyCamConfigPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    PixyCamConfigPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    PixyCamConfigPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    PixyCamConfigPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    PixyCamConfigPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    PixyCamConfigPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    PixyCamConfigPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    PixyCamConfigPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    PixyCamConfigPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    PixyCamConfigPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    PixyCamConfigPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    PixyCamConfigPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    plugin->typeCode =  (struct RTICdrTypeCode *)PixyCamConfig_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    PixyCamConfigPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    PixyCamConfigPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    PixyCamConfigPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = PixyCamConfigTYPENAME;

    return plugin;
}

void
PixyCamConfigPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
