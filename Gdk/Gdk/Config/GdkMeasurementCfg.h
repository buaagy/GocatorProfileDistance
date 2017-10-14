/**
* @file    GdkMeasurementCfg.h
* @brief   Declares the GdkMeasurementCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_MEASUREMENT_CFG_H
#define GDK_MEASUREMENT_CFG_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParams.h>

kBeginHeader()

/**
* Represents configuration for a measurement.
*
* @class       GdkMeasurementCfg
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkMeasurementCfg;

kDeclareInterface(Gdk, GdkMeasurementCfg, kNull)

/**
* Returns the measurement type name.
*
* @public               @memberof GdkMeasurementCfg
* @param    config      Configuration object.
* @return               Pointer to type name.
*/
GdkFx(const kChar*) GdkMeasurementCfg_Type(GdkMeasurementCfg config);

/**
* Returns the measurement ID.
*
* @public               @memberof GdkMeasurementCfg
* @param    config      Configuration object.
* @return               Measurement ID.
*/
GdkFx(k32s) GdkMeasurementCfg_Id(GdkMeasurementCfg config);

/**
* Returns the measurement name.
*
* @public               @memberof GdkMeasurementCfg
* @param    config      Configuration object.
* @return               Pointer to name.
*/
GdkFx(const kChar*) GdkMeasurementCfg_Name(GdkMeasurementCfg config);

/**
* Returns measurement enabled state.
*
* @public               @memberof GdkMeasurementCfg
* @param    config      Configuration object.
* @return               Enabled state.
*/
GdkFx(kBool) GdkMeasurementCfg_Enabled(GdkMeasurementCfg config);

/**
* Returns user-defined parameter set.
*
* @public               @memberof GdkMeasurementCfg
* @param    config      Configuration object.
* @return               Parameter set.
*/
GdkFx(GdkParams) GdkMeasurementCfg_Parameters(GdkMeasurementCfg config);

kEndHeader()

#endif 
