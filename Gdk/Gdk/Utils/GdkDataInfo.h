/**
* @file    GdkDataInfo.h
* @brief   Declares the GdkDataInfo class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_DATA_INFO_H
#define GDK_DATA_INFO_H

#include <Gdk/GdkDef.h>

kBeginHeader()

/**
* Describes a data source.
*
* @class       GdkDataInfo
* @extends     kObject
* @ingroup     Gdk-Utils
*/
typedef kObject GdkDataInfo;
kDeclareClass(Gdk, GdkDataInfo, kObject)

/**
* Returns the type of the data source.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Data source type.
*/
GdkFx(GdkDataType) GdkDataInfo_Type(GdkDataInfo info);

/**
* Returns the the data source position.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Data source position.
*/
GdkFx(GdkDataSource) GdkDataInfo_Source(GdkDataInfo info);

/**
* Returns whether or not intensity data is available.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Intensity presence.
*/
GdkFx(kBool) GdkDataInfo_HasIntensity(GdkDataInfo info);

/**
* Returns the data scales.
*
* Note: when simulating data recorded from a version older than 4.6, the scales
* obtained outside of the GdkTool_VProcess method may be inaccurate.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Data scales.
*/
GdkFx(const kPoint3d64f*) GdkDataInfo_Scale(GdkDataInfo info);

/**
* Returns the the data region.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Data region.
*/
GdkFx(const GdkRegion3d64f*) GdkDataInfo_Region(GdkDataInfo info);

/**
* Returns the the stream step.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Stream step.
*/
GdkFx(k32s) GdkDataInfo_StreamStep(GdkDataInfo info);

/**
* Returns the the stream ID.
*
* @public               @memberof GdkDataInfo
* @param    info        Info object.
* @return               Stream ID.
*/
GdkFx(k32s) GdkDataInfo_StreamId(GdkDataInfo info);


kEndHeader()

#endif 
