/**
* @file    GdkFeatureCfg.h
* @brief   Declares the GdkFeatureCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_FEATURE_CFG_H
#define GDK_FEATURE_CFG_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParams.h>

kBeginHeader()

/**
* Represents configuration for a measurement.
*
* @class       GdkFeatureCfg
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkFeatureCfg;

kDeclareInterface(Gdk, GdkFeatureCfg, kNull)

/**
* Returns the feature Data type.
*
* @public               @memberof GdkFeatureCfg
* @param    config      Configuration object.
* @return               Pointer to type name.
*/
GdkFx(GdkFeatureDataType) GdkFeatureCfg_DataType(GdkFeatureCfg config);

/**
* Returns the feature Type name.
*
* @public               @memberof GdkFeatureCfg
* @param    config      Configuration object.
* @return               Pointer to type name.
*/
GdkFx(const kChar*) GdkFeatureCfg_Type(GdkFeatureCfg config);

/**
* Returns the measurement ID.
*
* @public               @memberof GdkFeatureCfg
* @param    config      Configuration object.
* @return               Feature ID.
*/
GdkFx(k32s) GdkFeatureCfg_Id(GdkFeatureCfg config);

/**
* Returns the measurement name.
*
* @public               @memberof GdkFeatureCfg
* @param    config      Configuration object.
* @return               Pointer to name.
*/
GdkFx(const kChar*) GdkFeatureCfg_Name(GdkFeatureCfg config);

/**
* Returns measurement enabled state.
*
* @public               @memberof GdkFeatureCfg
* @param    config      Configuration object.
* @return               Enabled state.
*/
GdkFx(kBool) GdkFeatureCfg_Enabled(GdkFeatureCfg config);

/**
* Returns user-defined parameter set.
*
* @public               @memberof GdkFeatureCfg
* @param    config      Configuration object.
* @return               Parameter set.
*/
GdkFx(GdkParams) GdkFeatureCfg_Parameters(GdkFeatureCfg config);

kEndHeader()

#endif 
