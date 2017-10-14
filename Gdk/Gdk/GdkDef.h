/** 
 * @file    GdkDef.h
 * @brief   Essential Gdk declarations. 
 *
 * @internal
 * Copyright (C) 2013 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_DEF_H
#define GDK_DEF_H

#include <kApi/kApiDef.h>

kBeginHeader()

#if defined(GDK_EMIT)
#	define GdkFx(TYPE)       kExportFx(TYPE)
#	define GdkDx(TYPE)       kExportDx(TYPE)
#else
#	define GdkFx(TYPE)       kImportFx(TYPE)
#	define GdkDx(TYPE)       kImportDx(TYPE)
#endif

typedef struct GdkRegion2d64f
{
    k64f x;
    k64f y;
    k64f width;
    k64f length;
} GdkRegion2d64f;

typedef struct GdkRegion3d64f
{
    k64f x;
    k64f y;
    k64f z;
    k64f width;
    k64f length;
    k64f height;
    k64f zAngle;
} GdkRegion3d64f;

typedef struct GdkRegionXZ64f
{
    k64f x;
    k64f z;
    k64f width;
    k64f height;
} GdkRegionXZ64f;

typedef struct GdkPointXZ16s
{
    k16s x;
    k16s z;
} GdkPointXZ16s;

/**
* @struct  GdkTransform3d
* @extends kValue
* @ingroup Gdk
* @brief   3D transformation matrix

[ xx xy xz xt ]
[ yx yy yz yt ]
[ zx zy zz zt ]
[ 0  0  0  1  ]
*/

typedef struct
{
    k64f xx;
    k64f xy;
    k64f xz;
    k64f xt;

    k64f yx;
    k64f yy;
    k64f yz;
    k64f yt;

    k64f zx;
    k64f zy;
    k64f zz;
    k64f zt;

} GdkTransform3d;


GdkFx(kStatus) GdkRegion3d64f_FromRect(GdkRegion3d64f* region, const kRect3d64f* rect);
GdkFx(kStatus) GdkRegion3d64f_ToRect(const GdkRegion3d64f* region, kRect3d64f* rect);

/**
* @struct  GdkOrientation
* @extends kValue
* @ingroup Gdk
* @brief   Represents the sensor system orientation.
*/
typedef k32s GdkOrientation;

/** @relates GdkOrientation @{ */
#define GDK_ORIENTATION_WIDE         (0)             ///< Wide layout.
#define GDK_ORIENTATION_OPPOSITE     (1)             ///< Opposite layout.
#define GDK_ORIENTATION_REVERSE      (2)             ///< Reverse layout.
/** @} */

/**
* @struct  GdkDataSource
* @extends kValue
* @ingroup Gdk
* @brief   Represents a data source selections.
*/
typedef k32s GdkDataSource;

/** @relates GdkDataSource @{ */
#define GDK_DATA_SOURCE_NONE         (-1)            ///< None or invalid.
#define GDK_DATA_SOURCE_TOP          (0)             ///< Top.
#define GDK_DATA_SOURCE_BOTTOM       (1)             ///< Bottom.
#define GDK_DATA_SOURCE_TOP_LEFT     (2)             ///< Top left.
#define GDK_DATA_SOURCE_TOP_RIGHT    (3)             ///< Top right.
#define GDK_DATA_SOURCE_TOP_BOTTOM   (4)             ///< Top and bottom (separate data streams).
#define GDK_DATA_SOURCE_LEFT_RIGHT   (5)             ///< Left and right (separate data streams).
#define GDK_DATA_SOURCE_COUNT        (6)             ///< Reserved for internal use.
/** @} */

/**
* @struct  GdkDataType
* @extends kValue
* @ingroup Gdk
* @brief   Represents data source selections. Used as a bitmask.
*/
typedef k32s GdkDataType;

/** @relates GdkDataType @{ */
#define GDK_DATA_TYPE_NONE                   (0x1)           ///< None.
#define GDK_DATA_TYPE_RANGE                  (0x2)           ///< Range data.
#define GDK_DATA_TYPE_UNIFORM_PROFILE        (0x4)           ///< Uniformly-spaced (resampled) profile data.
#define GDK_DATA_TYPE_RAW_PROFILE            (0x8)           ///< Unresampled profile data.
#define GDK_DATA_TYPE_UNIFORM_SURFACE        (0x10)          ///< Uniformly-spaced height map.
#define GDK_DATA_TYPE_RAW_SURFACE            (0x20)          ///< Unresampled point cloud.
#define GDK_DATA_TYPE_UNMERGED_RAW_PROFILE   (0x40)          ///< Unmerged raw profile data. Reserved for future use.
#define GDK_DATA_TYPE_VIDEO                  (0x80)          ///< Video data.
#define GDK_DATA_TYPE_TRACHEID               (0x100)         ///< Tracheid data. Reserved for internal use.
#define GDK_DATA_TYPE_FEATURES_ONLY          (0x10000000)    ///< Geometric features only. No scan data.
/** @} */

/**
* @struct  GdkGraphicAnchorRegionType
* @extends kValue
* @ingroup Gdk
* @brief   Represents type of anchor region.
*/
typedef k8s GdkGraphicAnchorRegionType;

/** @relates GdkGraphicAnchorRegionType @{ */
#define GDK_GRAPHIC_ANCHOR_REGION_2D        (0x0)        
#define GDK_GRAPHIC_ANCHOR_REGION_3D        (0x1)
#define GDK_GRAPHIC_ANCHOR_REGION_2D_XY     (0x2)
/** @} */


/**
* @struct  GdkAnchorParam
* @extends kValue
* @ingroup Gdk
* @brief   Represents anchor parameter source selections.
*/
typedef k32s GdkAnchorParam;

/** @relates GdkAnchorParam @{ */
#define GDK_ANCHOR_PARAM_X          (0)         ///< X Axis.
#define GDK_ANCHOR_PARAM_Y          (1)         ///< Y Axis.
#define GDK_ANCHOR_PARAM_Z          (2)         ///< Z Axis.
#define GDK_ANCHOR_PARAM_Z_ANGLE    (3)         ///< Z Rotation Angle.
#define GDK_ANCHOR_PARAM_COUNT      (4)         ///< Reserved for internal use.
/** @} */

GdkFx(const kChar*) GdkAnchorParam_Format(GdkAnchorParam axis);

typedef k32s GdkAxis;

#define GDK_AXIS_X                   (0)             ///< X Axis.
#define GDK_AXIS_Y                   (1)             ///< Y Axis.
#define GDK_AXIS_Z                   (2)             ///< Z Axis.

/**
* @struct  GdkRefFrame
* @extends kValue
* @ingroup Gdk
* @brief   Represents data source selections.
*/
typedef k32s GdkRefFrame;

/** @relates GdkRefFrame @{ */
#define GDK_REF_FRAME_SENSOR         (0)             ///< Sensor frame of reference.
#define GDK_REF_FRAME_SCAN           (1)             ///< Scan frame of reference (X in sensor frame, Y in part frame).
#define GDK_REF_FRAME_PART           (2)             ///< Part frame of reference.
/** @} */

/**
* @struct  GdkMeasurementValueType
* @extends kValue
* @ingroup Gdk
* @brief   Represents data source selections.
*/
typedef k32s GdkMeasurementValueType;

/** @relates GdkMeasurementValueType @{ */
#define GDK_MEASUREMENT_VALUE_TYPE_VALUE     (0)         ///< Generic value.
#define GDK_MEASUREMENT_VALUE_TYPE_X         (1)         ///< X value (mm).
#define GDK_MEASUREMENT_VALUE_TYPE_Y         (2)         ///< Y value (mm).
#define GDK_MEASUREMENT_VALUE_TYPE_Z         (3)         ///< Z value (mm).
#define GDK_MEASUREMENT_VALUE_TYPE_X_ANGLE   (4)         ///< X angle (degrees).
#define GDK_MEASUREMENT_VALUE_TYPE_Y_ANGLE   (5)         ///< Y angle (degrees).
#define GDK_MEASUREMENT_VALUE_TYPE_Z_ANGLE   (6)         ///< Z angle (degrees).
/** @} */

/**
* @struct  GdkMeasurementDecision
* @extends kValue
* @ingroup Gdk
* @brief   Represents a measurement result decision.
*/
typedef k8u GdkMeasurementDecision;

/** @relates GdkMeasurementDecision @{ */
#define GDK_MEASUREMENT_OK               (0)         ///< No error.
#define GDK_MEASUREMENT_ERROR_VALUE      (0x2)       ///< Invalid measurement value.
#define GDK_MEASUREMENT_ERROR_ANCHOR     (0x4)       ///< Invalid anchor input.
#define GDK_MEASUREMENT_ERROR_PART_MATCH (0x8)       ///< Part matching failure.
/** @} */

/**
* @struct  ToolOutputType
* @extends k32s
* @ingroup Gdk
* @brief   Represents tool output type.
*/
typedef k32s GdkToolOutputType;

/** @relates GdkToolOutputType @{ */
#define GDK_TOOL_OUTPUT_TYPE_NULL           (0)
#define GDK_TOOL_OUTPUT_TYPE_MEASUREMENT    (1)
#define GDK_TOOL_OUTPUT_TYPE_FEATURE        (2)
#define GDK_TOOL_OUTPUT_TYPE_DIAGNOSTIC     (3)
/** @} */


/**
* @struct  GdkFeatureDataType
* @extends k32s
* @ingroup Gdk
* @brief   Represents geometric feature output type.
*/
typedef k32s GdkFeatureDataType;
/** @relates GdkFeatureDataType @{ */
#define GDK_FEATURE_TYPE_NULL   (-1)
#define GDK_FEATURE_TYPE_POINT  (0)
#define GDK_FEATURE_TYPE_LINE   (1)
#define GDK_FEATURE_TYPE_CIRCLE (2)
#define GDK_FEATURE_TYPE_PLANE  (3)
/** @} */
kDeclareEnum(Gdk, GdkFeatureDataType, kValue)

typedef k32s GdkGeometricFeatureId;

#define GDK_GEOMETRIC_FEATURE_ID_NONE       (-1)

GdkFx(const kChar*) GdkFeatureDataType_ToString(GdkFeatureDataType type);
GdkFx(GdkFeatureDataType) GdkFeatureDataType_ToType(const kChar* typeName);

typedef k32s GdkToolFormat;
#define GDK_TOOL_FORMAT_STANDARD (0)
#define GDK_TOOL_FORMAT_USER     (1)
#define GDK_TOOL_FORMAT_INTERNAL (2)

GdkFx(kStatus) GdkLogf(const kChar* message, ...);

kEndHeader()

#endif
