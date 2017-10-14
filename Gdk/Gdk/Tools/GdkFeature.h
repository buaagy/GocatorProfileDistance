/** 
 * @file    GdkFeature.h
 * @brief   Declares geometric feature class.
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_FEATURE_H
#define GDK_FEATURE_H

#include <Gdk/GdkDef.h>

kBeginHeader()

typedef kObject GdkFeature;

GdkFx(GdkFeatureDataType) GdkFeature_Type(GdkFeature feature);

kEndHeader()

#include <Gdk/Tools/GdkFeature.x.h>

#endif
