/** 
 * @file    GvFeature.h
 * @brief   GoVision feature header. 
 *
 * @internal
 * Copyright (C) 2013 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GV_FEATURE_H
#define GV_FEATURE_H

#include <kApi/kApiDef.h>

#ifndef GvFx
#define GvFx(TYPE)       kExportFx(TYPE) 
#endif

kBeginHeader()

//TODO: resolve this GvFeatureType is defined across mutiple projects!
#if defined(K_DSP_BIOS)
#pragma diag_suppress=303
#endif

typedef k32s GvFeatureType;
#define GV_FEATURE_POINT    (0)
#define GV_FEATURE_LINE     (1)
#define GV_FEATURE_CIRCLE   (2)
#define GV_FEATURE_PLANE    (3)


/* Feature Stuff */
typedef struct
{
    GvFeatureType type;
    kPoint3d64f position;
    kPoint3d64f orientation;
} GvFeature;

typedef GvFeature GvFeaturePoint;
typedef GvFeature GvFeaturePlane;
typedef GvFeature GvFeatureLine;

typedef struct GvFeatureCircle
{
    GvFeatureType type;
    kPoint3d64f position;
    kPoint3d64f orientation;
    k64f radius;
} GvFeatureCircle;

GvFx(kSize) GvUtils_ProtoFeatureSize(GvFeatureType featureType);
GvFx(GvFeatureType) GvUtils_ProtoFeatureType(const void* feature);
GvFx(kStatus) GvFeature_ToPoint(const GvFeaturePoint* feature, kPoint3d64f* position);
GvFx(kStatus) GvFeature_FromPoint(GvFeaturePoint* feature, const kPoint3d64f* position);
GvFx(kStatus) GvFeature_ToLine(const GvFeatureLine* feature, kPoint3d64f* point, kPoint3d64f* direction);
GvFx(kStatus) GvFeature_FromLine(GvFeatureLine* feature, const kPoint3d64f* point, const kPoint3d64f* direction);
GvFx(kStatus) GvFeature_ToPlane(const GvFeaturePlane* feature, k64f* originDistance, kPoint3d64f* normal);
GvFx(kStatus) GvFeature_FromPlane(GvFeaturePlane* feature, const k64f originDistance, const kPoint3d64f* normal);
GvFx(kStatus) GvFeature_ToCircle(const GvFeatureCircle* feature, kPoint3d64f* position, k64f* radius, kPoint3d64f* normal);
GvFx(kStatus) GvFeature_FromCircle(GvFeatureCircle* feature, const kPoint3d64f* position, const k64f radius, const kPoint3d64f* normal);

kEndHeader()

#endif
