/**
* @file    GdkToolCfg.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_TOOL_CFG_H
#define GDK_TOOL_CFG_H

#include <Gdk/Config/GdkMeasurementCfg.h>
#include <Gdk/Config/GdkFeatureCfg.h>
#include <Gdk/Config/GdkParams.h>

#include <Gdk/GdkDef.h>

kBeginHeader()

/**
* Represents configuration for a tool.
*
* @class       GdkToolCfg
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkToolCfg;
kDeclareInterface(Gdk, GdkToolCfg, kNull)

/**
* Returns the tool name.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @return               Pointer to type name.
*/
GdkFx(const kChar*) GdkToolCfg_Name(GdkToolCfg config);

/**
* Set the data source used by the tool.
*
* This function should be called only during configuration initialization.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @param    source      Data source.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolCfg_SetSource(GdkToolCfg config, GdkDataSource source);

/**
* Returns the data source used by the tool.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @return               Data source.
*/
GdkFx(GdkDataSource) GdkToolCfg_Source(GdkToolCfg config);

/**
* Set the anchor source used by the tool.
*
* This function should be called only during configuration initialization.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @param    axis        Anchoring parameter - axis or angle.
* @param    id          ID of source measurement.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolCfg_SetAnchor(GdkToolCfg config, GdkAnchorParam axis, k32s id);

/**
* Returns the anchor source used by the tool.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @param    axis        Anchoring parameter - axis or angle.
* @return               ID of source measurement.
*/
GdkFx(k32s) GdkToolCfg_Anchor(GdkToolCfg config, GdkAnchorParam axis);

/**
* Returns user-defined parameter set.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @return               Parameter set.
*/
GdkFx(GdkParams) GdkToolCfg_Parameters(GdkToolCfg config);

/**
* Add a new measurement to the tool.
*
* @public                   @memberof GdkToolCfg
* @param    config          Configuration object.
* @param    type            Type name of the measurement.
* @param    measurementCfg  Pointer to receive the new measurement.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolCfg_AddMeasurement(GdkToolCfg config, const kChar* type, GdkMeasurementCfg* measurementCfg);

/**
* Returns the number of measurements in the tool.
*
* @public               @memberof GdkToolCfg
* @return               Number of measurements.
*/
GdkFx(kSize) GdkToolCfg_MeasurementCount(GdkToolCfg config);

/**
* Returns the measurement at an index.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @param    index       Index of measurement.
* @return               Measurement handle.
*/
GdkFx(GdkMeasurementCfg) GdkToolCfg_MeasurementAt(GdkToolCfg config, kSize index);

/**
* Add a new feature to the tool.
*
* @public                   @memberof GdkToolCfg
* @param    config          Configuration object.
* @param    type            Type of the feature.
* @param    featureCfg      Pointer to receive the new feature.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolCfg_AddFeature(GdkToolCfg config, const kChar* type, GdkFeatureCfg* featureCfg);

/**
* Returns the number of features in the tool.
*
* @public               @memberof GdkToolCfg
* @return               Number of features.
*/
GdkFx(kSize) GdkToolCfg_FeatureCount(GdkToolCfg config);

/**
* Returns the measurement at an index.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @param    index       Index of feature.
* @return               Feature handle.
*/
GdkFx(GdkFeatureCfg) GdkToolCfg_FeatureAt(GdkToolCfg config, kSize index);

/**
* Sets the version of the configuration.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @param    version     Version of the config.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolCfg_SetVersion(GdkToolCfg config, const kChar* version);

/**
* Returns the version of the configuration.
*
* @public               @memberof GdkToolCfg
* @param    config      Configuration object.
* @return               Config version.
*/
GdkFx(const kChar*) GdkToolCfg_Version(GdkToolCfg config);

GdkFx(kBool) GdkToolCfg_VersionUnknown(GdkToolCfg config);

kEndHeader()

#endif 
