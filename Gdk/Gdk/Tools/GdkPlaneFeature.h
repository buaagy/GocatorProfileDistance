/** 
 * @file    GdkPlaneFeature.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_PLANE_FEATURE_H
#define GDK_PLANE_FEATURE_H

#include <Gdk/Tools/GdkFeature.h>

kBeginHeader()

/**
* Describes a GDK plane feature.
*
* @class       GdkPlaneFeature
* @extends     GdkFeature
* @ingroup     Gdk-Tools
*/
typedef GdkFeature GdkPlaneFeature;
kDeclareClass(Gdk, GdkPlaneFeature, GdkFeature)

/**
* Sets the origin distance of the plane feature.
*
* @public               @memberof GdkPlaneFeature
* @param    feature     Plane feature object.
* @param    point       Distance of plane from the origin to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkPlaneFeature_SetOriginDistance(GdkPlaneFeature feature, const k64f point);

/**
* Returns the distance from the origin of the plane feature.
*
* @public               @memberof GdkPlaneFeature
* @param    feature     Plane feature object.
* @return               Distance from origin of plane feature.
*/
GdkFx(k64f) GdkPlaneFeature_OriginDistance(GdkPlaneFeature feature);

/**
* Sets the normal of the plane feature.
*
* @public               @memberof GdkPlaneFeature
* @param    feature     Plane feature object.
* @param    normal      Reference to normal vector of plane to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkPlaneFeature_SetNormal(GdkPlaneFeature feature, const kPoint3d64f* normal);

/**
* Returns the normal of the plane feature.
*
* @public               @memberof GdkPlaneFeature
* @param    feature     Plane feature object.
* @param    normal      Reference to normal vector of plane.
* @return               Operation status.
*/
GdkFx(kStatus) GdkPlaneFeature_Normal(GdkPlaneFeature feature, kPoint3d64f* normal);

kEndHeader()

#include <Gdk/Tools/GdkPlaneFeature.x.h>

#endif
