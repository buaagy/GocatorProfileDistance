/** 
 * @file    GdkPointFeature.x.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_POINT_FEATURE_X_H
#define GDK_POINT_FEATURE_X_H

kBeginHeader()

typedef struct GdkPointFeatureClass
{
    GdkFeatureClass base;
} GdkPointFeatureClass;

#define GdkPointFeature_Cast_(FEATURE)                     kCastClass_(GdkPointFeature, FEATURE)

GdkFx(kStatus) GdkPointFeature_Construct(GdkPointFeature* feature, kAlloc alloc);
GdkFx(kStatus) GdkPointFeature_Init(GdkPointFeature feature, kType type, kAlloc allocator);
GdkFx(kStatus) GdkPointFeature_VRelease(GdkPointFeature feature);
GdkFx(kStatus) GdkPointFeature_VInitClone(GdkPointFeature feature, GdkPointFeature source, kAlloc allocator);

kEndHeader()

#endif
