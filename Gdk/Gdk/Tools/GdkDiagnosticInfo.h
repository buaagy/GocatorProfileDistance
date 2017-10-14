/**
* @file    GdkDiagnosticInfo.h
* @brief   Declares the GdkToolCfg class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_DIAGNOSTIC_INFO_H
#define GDK_DIAGNOSTIC_INFO_H

#include <Gdk/GdkDef.h>
#include <Gdk/Config/GdkParamsInfo.h>

kBeginHeader()

/**
* Describes a feature type.
*
* @class       GdkDiagnosticInfo
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkDiagnosticInfo;
kDeclareClass(Gdk, GdkDiagnosticInfo, kObject)


GdkFx(kStatus) GdkDiagnosticInfo_Construct(GdkDiagnosticInfo* info, kAlloc alloc);

/**
* Sets the feature type name.
*
* @public               @memberof GdkDiagnosticInfo
* @param    info        Info object.
* @param    name        Name of feature.
* @return               Operation status.
*/
GdkFx(kStatus) GdkDiagnosticInfo_SetName(GdkDiagnosticInfo info, const kChar* name);

/**
* Returns the feature type name.
*
* @public               @memberof GdkDiagnosticInfo
* @param    info        Info object.
* @return               Name of feature.
*/
GdkFx(const kChar*) GdkDiagnosticInfo_Name(GdkDiagnosticInfo info);

/**
* Sets the feature type id.
*
* @public               @memberof GdkDiagnosticInfo
* @param    info        Info object.
* @param    id        Id of feature.
* @return               Operation status.
*/
GdkFx(kStatus) GdkDiagnosticInfo_SetId(GdkDiagnosticInfo info, k32s id);

/**
* Returns the feature type id.
*
* @public               @memberof GdkDiagnosticInfo
* @param    info        Info object.
* @return               Id of feature.
*/
GdkFx(k32s) GdkDiagnosticInfo_Id(GdkDiagnosticInfo info);

kEndHeader()

#endif
