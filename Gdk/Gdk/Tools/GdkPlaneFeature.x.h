/** 
 * @file    GdkPlaneFeature.x.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_PLANE_FEATURE_X_H
#define GDK_PLANE_FEATURE_X_H

kBeginHeader()

typedef struct GdkPlaneFeatureClass
{
    GdkFeatureClass base;
} GdkPlaneFeatureClass;

#define GdkPlaneFeature_Cast_(FEATURE)                     kCastClass_(GdkPlaneFeature, FEATURE)

GdkFx(kStatus) GdkPlaneFeature_Construct(GdkPlaneFeature* feature, kAlloc alloc);
GdkFx(kStatus) GdkPlaneFeature_Init(GdkPlaneFeature feature, kType type, kAlloc allocator);
GdkFx(kStatus) GdkPlaneFeature_VRelease(GdkPlaneFeature feature);
GdkFx(kStatus) GdkPlaneFeature_VInitClone(GdkPlaneFeature feature, GdkPlaneFeature source, kAlloc allocator);

kEndHeader()

#endif
