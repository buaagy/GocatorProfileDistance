/**
* @file    GdkMeasurementInfo.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_MEASUREMENT_INFO_H
#define GDK_MEASUREMENT_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParamsInfo.h>

kBeginHeader()

/**
* Describes a measurement type.
*
* @class       GdkMeasurementInfo
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkMeasurementInfo;
kDeclareClass(Gdk, GdkMeasurementInfo, kObject)

/**
* Sets the measurement type name.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @param    name        Type name.
* @return               Operation status.
*/
GdkFx(kStatus) GdkMeasurementInfo_SetTypeName(GdkMeasurementInfo info, const kChar* name);

/**
* Returns the measurement type name.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @return               Type name.
*/
GdkFx(const kChar*) GdkMeasurementInfo_TypeName(GdkMeasurementInfo info);

/**
* Sets the measurement display label.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @param    label       Display label.
* @return               Operation status.
*/
GdkFx(kStatus) GdkMeasurementInfo_SetLabel(GdkMeasurementInfo info, const kChar* label);

/**
* Returns the measurement display label.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @return               Display label.
*/
GdkFx(const kChar*) GdkMeasurementInfo_Label(GdkMeasurementInfo info);

/**
* Sets the measurement value type.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @param    type        Type.
* @return               Operation status.
*/
GdkFx(kStatus) GdkMeasurementInfo_SetValueType(GdkMeasurementInfo info, GdkMeasurementValueType type);

/**
* Returns the measurement value type.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @return               Type.
*/
GdkFx(GdkMeasurementValueType) GdkMeasurementInfo_ValueType(GdkMeasurementInfo info);

/**
* Sets the minimum number of instances within a tool.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @param    count       Minimum instance count.
* @return               Operation status.
*/
GdkFx(kStatus) GdkMeasurementInfo_SetMinCount(GdkMeasurementInfo info, kSize count);

/**
* Returns the minimum number of instances within a tool.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @return               Minimum instance count.
*/
GdkFx(kSize) GdkMeasurementInfo_MinCount(GdkMeasurementInfo info);

/**
* Sets the maximum number of instances within a tool.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @param    count       Maximum instance count.
* @return               Operation status.
*/
GdkFx(kStatus) GdkMeasurementInfo_SetMaxCount(GdkMeasurementInfo info, kSize count);

/**
* Returns the minimum number of instances within a tool.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @return               Maximum instance count.
*/
GdkFx(kSize) GdkMeasurementInfo_MaxCount(GdkMeasurementInfo info);

/**
* Returns the schema for the parameters.
*
* @public               @memberof GdkMeasurementInfo
* @param    info        Info object.
* @return               Params info.
*/
GdkFx(GdkParamsInfo) GdkMeasurementInfo_Params(GdkMeasurementInfo info);

kEndHeader()

#endif
