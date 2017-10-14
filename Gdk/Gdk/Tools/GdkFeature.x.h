/** 
 * @file    GdkFeature.x.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_FEATURE_X_H
#define GDK_FEATURE_X_H

kBeginHeader()

typedef struct GdkFeatureClass
{
    kObjectClass base;
    GdkFeatureDataType type;
    kPoint3d64f position;
    kPoint3d64f orientation;
} GdkFeatureClass;

typedef struct GdkFeatureVTable
{
    kObjectVTable base;
} GdkFeatureVTable;

kDeclareVirtualClass(Gdk, GdkFeature, kObject)

#define GdkFeature_Cast_(FEATURE)                          kCastClass_(GdkFeature, FEATURE)
#define GdkFeature_VTable_(FEATURE)                        kCastVTable_(GdkFeature, FEATURE)

GdkFx(kStatus) GdkFeature_Init(GdkFeature feature, kType type, GdkFeatureDataType ftype, kAlloc allocator);
GdkFx(kStatus) GdkFeature_VRelease(GdkFeature feature);
GdkFx(kStatus) GdkFeature_SetType(GdkFeature feature, const GdkFeatureDataType type);

GdkFx(kStatus) GdkFeature_CopyBase(GdkFeature feature, GdkFeature source);

GdkFx(kStatus) GdkFeature_SetLocalFrame(GdkFeature feature, const kPoint3d64f* origin, const kPoint3d64f* orientation);
GdkFx(kStatus) GdkFeature_LocalFrame(GdkFeature feature, kPoint3d64f* origin, kPoint3d64f* orientation);

kEndHeader()

#endif
