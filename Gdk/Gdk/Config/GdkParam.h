/**
* @file    GdkParam.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_EXT_PARAM_H
#define GDK_EXT_PARAM_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParamInfo.h>

kBeginHeader()

/**
* Represents the data of a configurable parameter.
*
* @class       GdkParam
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkParam;
kDeclareClass(Gdk, GdkParam, kObject)

GdkFx(kStatus) GdkParam_Construct(GdkParam* param, GdkParamInfo info, kAlloc alloc);

GdkFx(kStatus) GdkParam_Assign(GdkParam param, GdkParam source);

/**
* Sets the used attribute.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    used        Used state.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetUsed(GdkParam param, kBool used);

/**
* Returns the used attribute.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Used state.
*/
GdkFx(kBool) GdkParam_Used(GdkParam param);

/**
* Returns whether or not an optional parameter has been set.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Set state.
*/
GdkFx(kBool) GdkParam_IsSet(GdkParam param);

/**
* Sets the value of an integer parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetInt(GdkParam param, k32s value);

/**
* Returns the value of an integer parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Parameter value.
*/
GdkFx(k32s) GdkParam_AsInt(GdkParam param);

/**
* Sets the value of a decimal parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetFloat(GdkParam param, k64f value);

/**
* Returns the value of an decimal parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Parameter value.
*/
GdkFx(k64f) GdkParam_AsFloat(GdkParam param);

/**
* Sets the value of a boolean parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetBool(GdkParam param, kBool value);

/**
* Returns the value of an boolean parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Parameter value.
*/
GdkFx(kBool) GdkParam_AsBool(GdkParam param);

/**
* Sets the value of a string parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetString(GdkParam param, const kChar* value);

/**
* Returns the value of a string parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Parameter value.
*/
GdkFx(const kChar*) GdkParam_AsString(GdkParam param);

/**
* Sets the value of a profile region parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetProfileRegion(GdkParam param, const GdkRegionXZ64f* value);

/**
* Returns the value of a profile region parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Pointer to parameter value.
*/
GdkFx(const GdkRegionXZ64f*) GdkParam_AsProfileRegion(GdkParam param);

/**
* Sets the value of a surface region parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetSurfaceRegion(GdkParam param, const GdkRegion3d64f* value);

/**
* Returns the value of a surface region parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Pointer to parameter value.
*/
GdkFx(const GdkRegion3d64f*) GdkParam_AsSurfaceRegion(GdkParam param);

/**
* Sets the value of a surface 2D region parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetSurfaceRegion2D(GdkParam param, const GdkRegion2d64f* value);

/**
* Returns the value of a surface 2D region parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @return               Pointer to parameter value.
*/
GdkFx(const GdkRegion2d64f*) GdkParam_AsSurfaceRegion2D(GdkParam param);

/**
* Sets the value of a geometric feature parameter.
*
* @public               @memberof GdkParam
* @param    param       Param object.
* @param    value       New parameter value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParam_SetGeometricFeature(GdkParam param, GdkGeometricFeatureId value);
GdkFx(GdkGeometricFeatureId) GdkParam_AsGeometricFeature(GdkParam param);

GdkFx(kStatus) GdkParam_EditableInfo(GdkParam param, GdkParamInfo* info);

kEndHeader()

#endif 
