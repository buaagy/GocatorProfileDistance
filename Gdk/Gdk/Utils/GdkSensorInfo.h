/**
* @file    GdkSensorInfo.h
* @brief   Declares the GdkSensorInfo class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_SENSOR_INFO_H
#define GDK_SENSOR_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Utils/GdkDataInfo.h>

kBeginHeader()

/**
* Describes the sensor system environment.
*
* @class       GdkSensorInfo
* @extends     kObject
* @ingroup     Gdk-Utils
*/
typedef kObject GdkSensorInfo;
kDeclareClass(Gdk, GdkSensorInfo, kObject)

/**
* Returns the sensor system orientation.
*
* @public               @memberof GdkSensorInfo
* @param    info        Info object.
* @return               Orientation.
*/
GdkFx(GdkOrientation) GdkSensorInfo_Orientation(GdkSensorInfo info);

/**
* Returns the descriptor for a specified data source.
*
* @public               @memberof GdkSensorInfo
* @param    info        Info object.
* @param    source      Data source.
* @return               Descriptor for data source. kNULL if not found.
*/
GdkFx(GdkDataInfo) GdkSensorInfo_DataSource(GdkSensorInfo info, GdkDataSource source);

/**
* Returns the serial number of the device running the tool.
*
* @public               @memberof GdkSensorInfo
* @param    info        Info object.
* @return               Sensor serial number.
*/
GdkFx(k32u) GdkSensorInfo_SerialNumber(GdkSensorInfo info);

kEndHeader()

#endif 
