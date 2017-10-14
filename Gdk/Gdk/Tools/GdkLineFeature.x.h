/** 
 * @file    GdkLineFeature.x.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_LINE_FEATURE_X_H
#define GDK_LINE_FEATURE_X_H

kBeginHeader()

typedef struct GdkLineFeatureClass
{
    GdkFeatureClass base;
} GdkLineFeatureClass;

#define GdkLineFeature_Cast_(FEATURE)                     kCastClass_(GdkLineFeature, FEATURE)

GdkFx(kStatus) GdkLineFeature_Construct(GdkLineFeature* feature, kAlloc alloc);
GdkFx(kStatus) GdkLineFeature_Init(GdkLineFeature feature, kType type, kAlloc allocator);
GdkFx(kStatus) GdkLineFeature_VRelease(GdkLineFeature feature);
GdkFx(kStatus) GdkLineFeature_VInitClone(GdkLineFeature feature, GdkLineFeature source, kAlloc allocator);

kEndHeader()

#endif
