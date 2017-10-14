/**
* @file    GdkParamsInfo.h
* @brief   Declares the GdkParamsInfo class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_EXT_PARAMS_INFO_H
#define GDK_EXT_PARAMS_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParamInfo.h>

kBeginHeader()

/**
* Represents the schema of a parameter set.
*
* @class       GdkParamsInfo
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkParamsInfo;
kDeclareClass(Gdk, GdkParamsInfo, kObject)

/**
* Add a parameter to the set.
*
* @public               @memberof GdkParamsInfo
* @param    info        Info object.
* @param    name        Parameter name.
* @param    type        Parameter type.
* @param    label       Parameter label.
* @param    paramInfo   Pointer to receive the parameter info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamsInfo_Add(GdkParamsInfo info, const kChar* name, GdkParamType type, const kChar* label, GdkParamInfo* paramInfo);

GdkFx(kStatus) GdkParamsInfo_AddInt(GdkParamsInfo info, const kChar* name, const kChar* label, k32s defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddFloat(GdkParamsInfo info, const kChar* name, const kChar* label, k64f defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddBool(GdkParamsInfo info, const kChar* name, const kChar* label, kBool defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddString(GdkParamsInfo info, const kChar* name, const kChar* label, const kChar* defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddProfileRegion(GdkParamsInfo info, const kChar* name, const kChar* label, const GdkRegionXZ64f* defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddSurfaceRegion(GdkParamsInfo info, const kChar* name, const kChar* label, const GdkRegion3d64f* defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddSurfaceRegion2D(GdkParamsInfo info, const kChar* name, const kChar* label, const GdkRegion2d64f* defVal, GdkParamInfo* paramInfo);
GdkFx(kStatus) GdkParamsInfo_AddGeometricFeature(GdkParamsInfo info, const kChar* name, const kChar* label, GdkParamInfo* paramInfo);

/**
* Removes a parameter from the set.
*
* @public               @memberof GdkParamsInfo
* @param    info        Info object.
* @param    index       Index of parameter to remove.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamsInfo_Remove(GdkParamsInfo info, kSize index);

/**
* Returns the number of parameters in the set.
*
* @public               @memberof GdkParamsInfo
* @param    info        Info object.
* @return               Parameter Count.
*/
GdkFx(kSize) GdkParamsInfo_Count(GdkParamsInfo info);

/**
* Returns the parameter at a specified index.
*
* @public               @memberof GdkParamsInfo
* @param    info        Info object.
* @param    index       Index of parameter to get.
* @return               Paramter info object.
*/
GdkFx(GdkParamInfo) GdkParamsInfo_At(GdkParamsInfo info, kSize index);

/**
* Returns the parameter with a specified name.
*
* @public               @memberof GdkParamsInfo
* @param    info        Info object.
* @param    name        Name of the parameter to get.
* @return               Paramter info object.
*/
GdkFx(GdkParamInfo) GdkParamsInfo_Find(GdkParamsInfo info, const kChar* name);

kEndHeader()

#endif 
