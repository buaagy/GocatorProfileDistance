/**
* @file    GdkParams.h
* @brief   Declares the GdkParams class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_EXT_PARAMS_H
#define GDK_EXT_PARAMS_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParam.h>
#include <Gdk/Config/GdkParamsInfo.h>

kBeginHeader()

/**
* Represents a set of parameters.
*
* @class       GdkParams
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkParams;
kDeclareClass(Gdk, GdkParams, kObject)

/**
* Returns the number of parameters in the set.
*
* @public               @memberof GdkParams
* @param    params      Params object.
* @return               Parameter Count.
*/
GdkFx(kSize) GdkParams_Count(GdkParams params);

/**
* Returns the parameter at a specified index.
*
* @public               @memberof GdkParams
* @param    params      Params object.
* @param    index       Index of parameter to get.
* @return               Paramter object.
*/
GdkFx(GdkParam) GdkParams_At(GdkParams params, kSize index);

/**
* Returns the parameter with a specified name.
*
* @public               @memberof GdkParams
* @param    params      Params object.
* @param    name        Name of the parameter to get.
* @return               Paramter object.
*/
GdkFx(GdkParam) GdkParams_Find(GdkParams params, const kChar* name);

/**
* Returns whether the parameter at a specified index is a geometric feature.
*
* @public               @memberof GdkParams
* @param    params      Params object.
* @param    index       Index of parameter to get.
* @return               kTRUE if so, kFALSE otherwise.
*/
GdkFx(kBool)GdkParams_IsFeature(GdkParams params, kSize index);

/**
* Returns the count of geometric feature parameters.
*
* @public               @memberof GdkParams
* @param    params      Params object.
* @return               Count of params of type geometric features.
*/
GdkFx(kSize) GdkParams_FeatureParamsCount(GdkParams params);

kEndHeader()

#endif 
