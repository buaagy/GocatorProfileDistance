/** 
 * @file    GdkCircleFeature.x.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_CIRCLE_FEATURE_X_H
#define GDK_CIRCLE_FEATURE_X_H

kBeginHeader()

typedef struct GdkCircleFeatureClass
{
    GdkFeatureClass base;
    k64f radius;
} GdkCircleFeatureClass;

#define GdkCircleFeature_Cast_(FEATURE)                     kCastClass_(GdkCircleFeature, FEATURE)

GdkFx(kStatus) GdkCircleFeature_Construct(GdkCircleFeature* feature, kAlloc alloc);
GdkFx(kStatus) GdkCircleFeature_Init(GdkCircleFeature feature, kType type, kAlloc allocator);
GdkFx(kStatus) GdkCircleFeature_VRelease(GdkCircleFeature feature);
GdkFx(kStatus) GdkCircleFeature_VInitClone(GdkCircleFeature feature, GdkCircleFeature source, kAlloc allocator);

kEndHeader()

#endif
