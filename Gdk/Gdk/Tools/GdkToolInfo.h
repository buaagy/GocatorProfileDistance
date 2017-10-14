/**
* @file    GdkToolInfo.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_TOOL_INFO_H
#define GDK_TOOL_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Tools/GdkMeasurementInfo.h>
#include <Gdk/Tools/GdkFeatureInfo.h>
#include <Gdk/Tools/GdkDiagnosticInfo.h>
#include <Gdk/Tools/GdkToolVersionInfo.h>
#include <Gdk/Config/GdkParamsInfo.h>

kBeginHeader()

/**
* Describes a tool type.
*
* @class       GdkToolInfo
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkToolInfo;
kDeclareClass(Gdk, GdkToolInfo, kObject)

/**
* Adds a tool configuration version.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    name        Version name (can be empty string).
* @param    newVersion  Pointer to receive new version object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_AddVersion(GdkToolInfo info, const kChar* name, GdkToolVersionInfo* newVersion);

/**
* Returns the first version info object. This object is implicitly added and is
* used by GdkToolInfo methods that access version information directly.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Version info object.
*/
GdkFx(GdkToolVersionInfo) GdkToolInfo_FirstVersion(GdkToolInfo info);

/**
* Finds version object by name.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    name        Version name (can be empty string).
* @return               Found version object or kNULL.
*/
GdkFx(GdkToolVersionInfo) GdkToolInfo_FindVersion(GdkToolInfo info, const kChar* name);

/**
* Return the default version object. This is the version information that is
* used when a new tool is instantiated.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Version object.
*/
GdkFx(GdkToolVersionInfo) GdkToolInfo_DefaultVersion(GdkToolInfo info);

/**
* Sets the default version object.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    version     Version object that should be used as the default for new tool instances.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_SetDefaultVersion(GdkToolInfo info, GdkToolVersionInfo version);

/**
* Returns the number of version objects. Note that this always at least 1.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Number of version objects.
*/
GdkFx(kSize) GdkToolInfo_VersionCount(GdkToolInfo info);

/**
* Returns the version object at the specified index.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    index       Index of version object.
* @return               Version object at index.
*/
GdkFx(GdkToolVersionInfo) GdkToolInfo_VersionAt(GdkToolInfo info, kSize index);

/**
* Convenience method for setting the name of the first version.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    name        Version name.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_SetFirstVersionName(GdkToolInfo info, const kChar* name);

/**
* Sets the tool type name.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    name        Type name.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_SetTypeName(GdkToolInfo info, const kChar* name);

/**
* Returns the tool type name.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Type name.
*/
GdkFx(const kChar*) GdkToolInfo_TypeName(GdkToolInfo info);

/**
* Sets the tool display label.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    label       Display label.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_SetLabel(GdkToolInfo info, const kChar* label);

/**
* Returns the tool display label.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Display label.
*/
GdkFx(const kChar*) GdkToolInfo_Label(GdkToolInfo info);

/**
* Sets the data source type accepted by the tool.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    type        Data source type.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_SetSourceType(GdkToolInfo info, GdkDataType type);

/**
* Returns the data source type accepted by the tool.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Data source type.
*/
GdkFx(GdkDataType) GdkToolInfo_SourceType(GdkToolInfo info);

/**
* Add an option to the list of acceptable data sources.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    source      Data source option.
* @return               Data type.
*/
GdkFx(kStatus) GdkToolInfo_AddSourceOption(GdkToolInfo info, GdkDataSource source);

/**
* Clears the list of acceptable data sources.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_ClearSourceOptions(GdkToolInfo info);

/**
* Returns the number of acceptable data sources.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Data source count.
*/
GdkFx(kSize) GdkToolInfo_SourceOptionCount(GdkToolInfo info);

/**
* Returns the data source option at a specified index.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    index       Index of data source.
* @return               Data source.
*/
GdkFx(GdkDataSource) GdkToolInfo_SourceOptionAt(GdkToolInfo info, kSize index);

/**
* Sets whether or not this tool requires intensity data.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    required    Whether or not intensity is required.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_RequireIntensity(GdkToolInfo info, kBool required);

/**
* Returns whether or not this tool requires intensity data.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Intensity requirement.
*/
GdkFx(kBool) GdkToolInfo_IntensityRequired(GdkToolInfo info);

/**
* Enables or disables anchoring capability for a specified anchoring parameter.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    axis        Anchoring parameter - axis or angle.
* @param    enabled     Enabled state.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_EnableAnchoring(GdkToolInfo info, GdkAnchorParam axis, kBool enabled);

/**
* Checks anchoring capability for a specified anchoring parameter.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    axis        Anchoring parameter - axis or angle.
* @return               Whether or not anchoring capability is enabled.
*/
GdkFx(kBool) GdkToolInfo_AnchoringEnabled(GdkToolInfo info, GdkAnchorParam axis);

/**
* Returns the schema for the parameters.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Params info.
*/
GdkFx(GdkParamsInfo) GdkToolInfo_Params(GdkToolInfo info);

/**
* Add a measurement type.
*
* @public                   @memberof GdkToolInfo
* @param    info            Info object.
* @param    type            Measurement type name (should be unique within the tool).
* @param    measurementInfo Pointer to receive the new measurement info.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolInfo_AddMeasurement(GdkToolInfo info, const kChar* type, GdkMeasurementInfo* measurementInfo);

/**
* Clears measurement types.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_ClearMeasurements(GdkToolInfo info);

/**
* Returns the number of measurement types.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Measurement type count.
*/
GdkFx(kSize) GdkToolInfo_MeasurementCount(GdkToolInfo info);

/**
* Returns the measurement type at a specified index.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    index       Measurement type index.
* @return               Measurement type.
*/
GdkFx(GdkMeasurementInfo) GdkToolInfo_MeasurementAt(GdkToolInfo info, kSize index);

/**
* Add a feature type.
*
* @public                   @memberof GdkToolInfo
* @param    info            Info object.
* @param    type            Feature Type String
* @param    dataType        Feature data type (Point, Circle, etc).
* @param    featureInfo Pointer to receive the new feature info.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolInfo_AddFeature(GdkToolInfo info, const kChar* type, GdkFeatureDataType dataType, GdkFeatureInfo* featureInfo);

/**
* Clears feature types.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_ClearFeatures(GdkToolInfo info);

/**
* Returns the number of feature types.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Feature type count.
*/
GdkFx(kSize) GdkToolInfo_FeatureCount(GdkToolInfo info);

/**
* Returns the feature type at a specified index.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    index       Feature type index.
* @return               Feature type.
*/
GdkFx(GdkFeatureInfo) GdkToolInfo_FeatureAt(GdkToolInfo info, kSize index);

/**
* Adds a Diagnostic output to a tool with the specified index

* @public                   @memberof GdkToolInfo
* @param    info            Info object.
* @param    name            Diagnostic name. //Not currently used for anything. Can be kNULL
* @param    id              Diagnostic id (must be unique to tool). //Not currently used for anything
* @param    diagnosticInfo  Pointer to receive the new diagnostic's info.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkToolInfo_AddDiagnostic(GdkToolInfo info, const kChar* name, k32s id, GdkDiagnosticInfo* diagnosticInfo);

/**
* Returns the number of diagnostics.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               diagnostic count.
*/
GdkFx(kSize) GdkToolInfo_DiagnosticCount(GdkToolInfo info);

/**
* Clears (removes) all diagnostic outputs from tool.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolInfo_ClearDiagnostics(GdkToolInfo info);

/**
* Returns the diagnostic info of the diagnostic with the specified index.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    index       diagnostic index.
* @return               Diagnostic Info
*/
GdkFx(GdkDiagnosticInfo) GdkToolInfo_DiagnosticAt(GdkToolInfo info, kSize index);

/**
* Returns the id of the diagnostic with the specified index.
*
* @public               @memberof GdkToolInfo
* @param    info        Info object.
* @param    index       diagnostic index.
* @return               Diagnostic Id
*/
GdkFx(k32s) GdkToolInfo_DiagnosticIdAt(GdkToolInfo info, kSize index);

/**
* Marks the tool as an internal (LMI-Developed) tool
* 
* @private              @memberof GdkToolInfo
* @param    info        info object
* @return               Status of operation
*/
GdkFx(kStatus) GdkToolInfo_SetInternal(GdkToolInfo info);

/**
* Returns True if the tool is an internal (LMI-Developed) tool
*
* @private              @memberof GdkToolInfo
* @param    info        info object
* @return               Is the tool internal?
*/
GdkFx(kBool) GdkToolInfo_IsInternal(GdkToolInfo info);

/**
* Marks the tool as requiring a tool-license
*
* @private                  @memberof GdkToolInfo
* @param    info            info object
* @param    requiresLicense Boolean: Does the tool require a license?
* @return                   Status of operation
*/
GdkFx(kStatus) GdkToolInfo_SetRequiresLicense(GdkToolInfo info, kBool requiresLicense);

/**
* Returns true if the tool requires a tool license
*
* @private                  @memberof GdkToolInfo
* @param    info            info object
* @return                   kTRUE if tool requires a license
*/
GdkFx(kBool) GdkToolInfo_RequiresLicense(GdkToolInfo info);
kEndHeader()

#endif 
