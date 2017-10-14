/** 
 * @file    GdkTool.h
 * @brief   Declares the GdkTool class.
 *
 * Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_TOOL_H
#define GDK_TOOL_H

#include <Gdk/GdkDef.h>
#include <Gdk/Tools/GdkToolInfo.h>
#include <Gdk/Config/GdkToolCfg.h>
#include <Gdk/Tools/GdkToolInput.h>
#include <Gdk/Tools/GdkToolOutput.h>
#include <Gdk/Utils/GdkSensorInfo.h>
#include <Gdk/Tools/GdkPointFeature.h>
#include <Gdk/Tools/GdkLineFeature.h>
#include <Gdk/Tools/GdkCircleFeature.h>
#include <Gdk/Tools/GdkPlaneFeature.h>

kBeginHeader()

typedef struct GdkToolEnv
{
    GdkSensorInfo sensorInfo;
} GdkToolEnv;

/**
* Base class for a tool implementation.
*
* @class       GdkTool
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkTool;

/**
* Returns the tool configuration.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @return               Current configuration object.
*/
GdkFx(GdkToolCfg) GdkTool_Config(GdkTool tool);

/**
* Returns the sensor information.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @return               Current sensor info.
*/
GdkFx(GdkSensorInfo) GdkTool_SensorInfo(GdkTool tool);

/**
* Returns the index for the named feature.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @param   name         String name of feature.
* @return               Index of feature with matching name.
*/
GdkFx(kSize) GdkTool_InputFeatureIndex(GdkTool tool, const kChar* name);

/**
* Find the index of a measurement by its type name.
*
* If there are multiple measurements of the same type, only the index of
* first instance will be returned. A full list of measurements can be found
* in the tool config (see GdkTool_Config).
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @param   typeName     Type name of the measurement.
* @return               Index of measurement. kSIZE_NULL if not found.
*/
GdkFx(kSize) GdkTool_MeasuremenIndexByType(GdkTool tool, const kChar* typeName);

/**
* Find the index of a feature by its type name.
*
* If there are multiple features of the same type, only the index of
* first instance will be returned. A full list of features can be found
* in the tool config. See GdkTool_Config.
*
* The type name of the feature should not be confused with its data type.
* See GdkToolInfo_AddFeature.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @param   typeName     Type name of the feature.
* @return               Index of feature. kSIZE_NULL if not found.
*/
GdkFx(kSize) GdkTool_FeatureIndexByType(GdkTool tool, const kChar* typeName);

/**
* Applies the currently available anchoring parameters to a profile region.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @param   original     Pointer to original region.
* @param   anchored     Pointer to receive the anchor-adjusted region.
* @return               Operation status.
*/
GdkFx(kStatus) GdkTool_AnchorProfileRegion(GdkTool tool, const GdkRegionXZ64f* original, GdkRegionXZ64f* anchored);

/**
* Applies the currently available anchoring parameters to a surface region.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @param   original     Pointer to original region.
* @param   anchored     Pointer to receive the anchor-adjusted region.
* @return               Operation status.
*/
GdkFx(kStatus) GdkTool_AnchorSurfaceRegion(GdkTool tool, const GdkRegion3d64f* original, GdkRegion3d64f* anchored);

kEndHeader()

#include <Gdk/Tools/GdkTool.x.h>

#endif
