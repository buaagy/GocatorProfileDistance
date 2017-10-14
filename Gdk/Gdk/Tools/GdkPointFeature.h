/** 
 * @file    GdkPointFeature.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_POINT_FEATURE_H
#define GDK_POINT_FEATURE_H

#include <Gdk/Tools/GdkFeature.h>

kBeginHeader()

/**
* Describes a GDK point feature.
*
* @class       GdkPointFeature
* @extends     GdkFeature
* @ingroup     Gdk-Tools
*/
typedef GdkFeature GdkPointFeature;
kDeclareClass(Gdk, GdkPointFeature, GdkFeature)

/**
* Sets the position of the point feature.
*
* @public               @memberof GdkPointFeature
* @param    feature     Point feature object.
* @param    position    Position of point to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkPointFeature_SetPosition(GdkPointFeature feature, const kPoint3d64f* position);

/**
* Returns the position of the point feature.
*
* @public               @memberof GdkPointFeature
* @param    feature     Point feature object.
* @return               Reference to position of point feature.
*/
GdkFx(const kPoint3d64f*) GdkPointFeature_Position(GdkPointFeature feature);

kEndHeader()

#include <Gdk/Tools/GdkPointFeature.x.h>

#endif
