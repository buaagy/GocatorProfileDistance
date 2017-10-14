/**
* @file    GdkToolVersionInfo.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_TOOL_VERSION_INFO_H
#define GDK_TOOL_VERSION_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Tools/GdkMeasurementInfo.h>
#include <Gdk/Tools/GdkFeatureInfo.h>
#include <Gdk/Config/GdkParamsInfo.h>

kBeginHeader()

/**
* Describes a tool config version. A version consists of a set of parameters, measurements,
* and the parameters of those measurements.
*
* @class       GdkToolVersionInfo
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkToolVersionInfo;
kDeclareClass(Gdk, GdkToolVersionInfo, kObject)

/**
* Use another version as the base for this version. All parameters and measurements
* are copied.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @param    source      Source info object.
* @return               Params info.
*/
GdkFx(kStatus) GdkToolVersionInfo_UseBase(GdkToolVersionInfo info, GdkToolVersionInfo source);

/**
* Returns the schema for the parameters.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @return               Params info.
*/
GdkFx(GdkParamsInfo) GdkToolVersionInfo_Params(GdkToolVersionInfo info);

/**
* Add a measurement type.
*
* @public                   @memberof GdkToolVersionInfo
* @param    info            Info object.
* @param    type            Measurement type name (should be unique within the tool).
* @param    measurementInfo Pointer to receive the new measurement info.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolVersionInfo_AddMeasurement(GdkToolVersionInfo info, const kChar* type, GdkMeasurementInfo* measurementInfo);

/**
* Clears measurement types.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolVersionInfo_ClearMeasurements(GdkToolVersionInfo info);

/**
* Returns the number of measurement types.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @return               Measurement type count.
*/
GdkFx(kSize) GdkToolVersionInfo_MeasurementCount(GdkToolVersionInfo info);

/**
* Returns the measurement type at a specified index.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @param    index       Measurement type index.
* @return               Measurement type.
*/
GdkFx(GdkMeasurementInfo) GdkToolVersionInfo_MeasurementAt(GdkToolVersionInfo info, kSize index);

/**
* Add a feature type.
*
* @public                   @memberof GdkToolVersionInfo
* @param    info            Info object.
* @param    type            Feature type. 
* @param    dataType        Type of feature data (Line, Circle, etc)
* @param    featureInfo Pointer to receive the new feature info.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolVersionInfo_AddFeature(GdkToolVersionInfo info, const kChar* type, GdkFeatureDataType dataType, GdkFeatureInfo* featureInfo);

/**
* Clears feature types.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolVersionInfo_ClearFeatures(GdkToolVersionInfo info);

/**
* Returns the number of feature types.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @return               Feature type count.
*/
GdkFx(kSize) GdkToolVersionInfo_FeatureCount(GdkToolVersionInfo info);

/**
* Returns the feature type at a specified index.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @param    index       Feature type index.
* @return               Feature type.
*/
GdkFx(GdkFeatureInfo) GdkToolVersionInfo_FeatureAt(GdkToolVersionInfo info, kSize index);

/**
* Sets the version name. If the name is specified as kNULL, a version will
* automatically be generated based on the contents of the version object.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @param    version     Version name (can be empty string or kNULL).
* @return               Found version object or kNULL.
*/
GdkFx(kStatus) GdkToolVersionInfo_SetName(GdkToolVersionInfo info, const kChar* version);

/**
* Returns the version name.
*
* @public               @memberof GdkToolVersionInfo
* @param    info        Info object.
* @return               Version name.
*/
GdkFx(const kChar*) GdkToolVersionInfo_Name(GdkToolVersionInfo info);

kEndHeader()

#endif 
