/**
* @file    GdkFeatureInfo.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_FEATURE_INFO_H
#define GDK_FEATURE_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParamsInfo.h>

kBeginHeader()

/**
* Describes a feature type.
*
* @class       GdkFeatureInfo
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkFeatureInfo;
kDeclareClass(Gdk, GdkFeatureInfo, kObject)


GdkFx(kStatus) GdkFeatureInfo_Construct(GdkFeatureInfo* info, kAlloc alloc);

/**
* Sets the feature display label.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @param    label       Display label.
* @return               Operation status.
*/
GdkFx(kStatus) GdkFeatureInfo_SetLabel(GdkFeatureInfo info, const kChar* label);

/**
* Returns the feature display label.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @return               Display label.
*/
GdkFx(const kChar*) GdkFeatureInfo_Label(GdkFeatureInfo info);

GdkFx(kStatus) GdkFeatureInfo_SetType(GdkFeatureInfo info, const kChar* type);
GdkFx(kChar*) GdkFeatureInfo_Type(GdkFeatureInfo info);

/**
* Sets the feature type.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @param    type        Feature type.
* @return               Operation status.
*/
GdkFx(kStatus) GdkFeatureInfo_SetDataType(GdkFeatureInfo info, GdkFeatureDataType type);

/**
* Returns the feature type.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @return               Feature type.
*/
GdkFx(GdkFeatureDataType) GdkFeatureInfo_DataType(GdkFeatureInfo info);

/**
* Sets the minimum number of instances within a tool.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @param    count       Minimum instance count.
* @return               Operation status.
*/
GdkFx(kStatus) GdkFeatureInfo_SetMinCount(GdkFeatureInfo info, kSize count);

/**
* Returns the minimum number of instances within a tool.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @return               Minimum instance count.
*/
GdkFx(kSize) GdkFeatureInfo_MinCount(GdkFeatureInfo info);

/**
* Sets the maximum number of instances within a tool.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @param    count       Maximum instance count.
* @return               Operation status.
*/
GdkFx(kStatus) GdkFeatureInfo_SetMaxCount(GdkFeatureInfo info, kSize count);

/**
* Returns the minimum number of instances within a tool.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @return               Maximum instance count.
*/
GdkFx(kSize) GdkFeatureInfo_MaxCount(GdkFeatureInfo info);

/**
* Returns the schema for the parameters.
*
* @public               @memberof GdkFeatureInfo
* @param    info        Info object.
* @return               Params info.
*/
GdkFx(GdkParamsInfo) GdkFeatureInfo_Params(GdkFeatureInfo info);

kEndHeader()

#endif
