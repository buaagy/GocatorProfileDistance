/**
* @file    GdkParamInfo.h
* @brief   Declares the GdkParamInfo class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_EXT_PARAM_INFO_H
#define GDK_EXT_PARAM_INFO_H

#include <Gdk/GdkDef.h>

kBeginHeader()

/**
* Represents the schema of a configurable parameter.
*
* @class       GdkParamInfo
* @extends     kObject
* @ingroup     Gdk-Config
*/
typedef kObject GdkParamInfo;
kDeclareClass(Gdk, GdkParamInfo, kObject)

/**
* @struct  GdkParamType
* @extends kValue
* @ingroup Gdk-Config
* @brief   Type of a parameter.
*/
typedef k32s GdkParamType;

/** @relates GdkParamType @{ */
#define GDK_PARAM_TYPE_INT               (0)         ///< Integer.
#define GDK_PARAM_TYPE_FLOAT             (1)         ///< Float.
#define GDK_PARAM_TYPE_BOOL              (2)         ///< Boolean.
#define GDK_PARAM_TYPE_STRING            (3)         ///< String.
#define GDK_PARAM_TYPE_PROFILE_REGION    (4)         ///< Profile region.
#define GDK_PARAM_TYPE_SURFACE_REGION    (5)         ///< Surface region.
#define GDK_PARAM_TYPE_SURFACE_REGION_2D (6)         ///< Surface 2D region (X and Y).
#define GDK_PARAM_TYPE_GEOMETRIC_FEATURE (7)         ///< A set of geometric features
/** @} */

/**
* Returns the parameter type.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Parameter type.
*/
GdkFx(GdkParamType) GdkParamInfo_Type(GdkParamInfo info);

GdkFx(kBool) GdkParamInfo_IsFeatureInput(GdkParamInfo info);

/**
* Sets the name of the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    name        Parameter name.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetName(GdkParamInfo info, const kChar* name);

/**
* Returns the name of the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Parameter name.
*/
GdkFx(const kChar*) GdkParamInfo_Name(GdkParamInfo info);

/**
* Sets a parameter to be optional or not. An optional parameter can be
* missing from the configuration (e.g. when loaded from storage).
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    optional    Whether or not parameter is optional.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetIsOptional(GdkParamInfo info, kBool optional);

/**
* Returns whether or not the parameter is optional.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Is optional.
*/
GdkFx(kBool) GdkParamInfo_IsOptional(GdkParamInfo info);

/**
* Sets the display label of the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    label       Parameter label.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetLabel(GdkParamInfo info, const kChar* label);

/**
* Returns the display label of the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Parameter label.
*/
GdkFx(const kChar*) GdkParamInfo_Label(GdkParamInfo info);

/**
* Sets the units of the parameter.
*
* It is optional to specify the units.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    units       Parameter units.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetUnits(GdkParamInfo info, const kChar* units);

/**
* Returns the units of the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Parameter units (empty string if not set).
*/
GdkFx(const kChar*) GdkParamInfo_Units(GdkParamInfo info);

/**
* Returns the number of options for the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Number of options.
*/
GdkFx(kSize) GdkParamInfo_OptionCount(GdkParamInfo info);

/**
* Returns the option name at a specified index.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    index       Option index.
* @return               Option name.
*/
GdkFx(const kChar*) GdkParamInfo_OptionNameAt(GdkParamInfo info, kSize index);

/**
* Remove the option at a specified index.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    index       Option index.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_RemoveOption(GdkParamInfo info, kSize index);

/**
* Clears all options for the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_ClearOptions(GdkParamInfo info);

/**
* Sets the minimum value for an integer parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    min         Minimum value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetMinInt(GdkParamInfo info, k32s min);

/**
* Returns the minimum value for an integer parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Minimum value.
*/
GdkFx(k32s) GdkParamInfo_MinInt(GdkParamInfo info);

/**
* Sets the maximum value for an integer parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    max         Maximum value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetMaxInt(GdkParamInfo info, k32s max);

/**
* Returns the maximum value for an integer parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Maximum value.
*/
GdkFx(k32s) GdkParamInfo_MaxInt(GdkParamInfo info);

/**
* Add an option for an integer parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    option      Option value.
* @param    name        Option name.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_AddOptionInt(GdkParamInfo info, k32s option, const kChar* name);

/**
* Returns the option at a specified index for an integer parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    index       Option index.
* @return               Option value.
*/
GdkFx(k32s) GdkParamInfo_OptionAtInt(GdkParamInfo info, kSize index);

GdkFx(kStatus) GdkParamInfo_AddOptionFeatureId(GdkParamInfo info, GdkGeometricFeatureId option);
GdkFx(GdkGeometricFeatureId) GdkParamInfo_OptionFeatureId(GdkParamInfo info, kSize index);

/**
* Sets the minimum value for a decimal parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    min         Minimum value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetMinFloat(GdkParamInfo info, k64f min);

/**
* Returns the minimum value for a decimal parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Minimum value.
*/
GdkFx(k64f) GdkParamInfo_MinFloat(GdkParamInfo info);

/**
* Sets the maximum value for a decimal parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    max         Maximum value.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetMaxFloat(GdkParamInfo info, k64f max);

/**
* Returns the maximum value for a decimal parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @return               Maximum value.
*/
GdkFx(k64f) GdkParamInfo_MaxFloat(GdkParamInfo info);

/**
* Assign the default value of the parameter to sue when refreshing the parameter.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    value       Pointer to default value to assign.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_SetDefault(GdkParamInfo info, const void* value);

/**
* Enables Z angle support for the surface region passed.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object - expected to be a parameter of type GDK_PARAM_TYPE_SURFACE_REGION.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_EnableSurfaceRegionZAngle(GdkParamInfo info);

/**
* If the parameter is a Multiple Feature Type Input, add an accepted feature type.
*
* @public               @memberof GdkParamInfo
* @param    info        Info object.
* @param    type       Type to add.
* @return               Operation status.
*/
GdkFx(kStatus) GdkParamInfo_AddFeatureType(GdkParamInfo info, GdkFeatureDataType type);

kEndHeader()

#endif 
