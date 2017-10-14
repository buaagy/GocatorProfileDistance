/** 
 * @file    GdkCircleFeature.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_CIRCLE_FEATURE_H
#define GDK_CIRCLE_FEATURE_H

#include <Gdk/Tools/GdkFeature.h>

kBeginHeader()

/**
* Describes a GDK circle feature.
*
* @class       GdkCircleFeature
* @extends     GdkFeature
* @ingroup     Gdk-Tools
*/
typedef GdkFeature GdkCircleFeature;
kDeclareClass(Gdk, GdkCircleFeature, GdkFeature)

/**
* Sets the position of the circle feature.
*
* @public               @memberof GdkCircleFeature
* @param    feature     Circle feature object.
* @param    position    Reference to center position of circle to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkCircleFeature_SetPosition(GdkCircleFeature feature, const kPoint3d64f* position);

/**
* Returns the position of the circle feature.
*
* @public               @memberof GdkCircleFeature
* @param    feature     Circle feature object.
* @return               Position of circle feature.
*/
GdkFx(const kPoint3d64f*) GdkCircleFeature_Position(GdkCircleFeature feature);

/**
* Sets the radius of the circle feature.
*
* @public               @memberof GdkCircleFeature
* @param    feature     Circle feature object.
* @param    radius      Radius of circle to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkCircleFeature_SetRadius(GdkCircleFeature feature, const k64f radius);

/**
* Returns the radius of the circle feature.
*
* @public               @memberof GdkCircleFeature
* @param    feature     Circle feature object.
* @return               Radius of circle feature.
*/
GdkFx(k64f) GdkCircleFeature_Radius(GdkCircleFeature feature);

/**
* Sets the normal of the circle feature.
*
* @public               @memberof GdkCircleFeature
* @param    feature     Circle feature object.
* @param    normal    Reference to normal vector of circle to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkCircleFeature_SetNormal(GdkCircleFeature feature, const kPoint3d64f* normal);

/**
* Returns the normal of the circle feature.
*
* @public               @memberof GdkCircleFeature
* @param    feature     Circle feature object.
* @param    normal      Reference to normal vector of circle.
* @return               Operation status.
*/
GdkFx(kStatus) GdkCircleFeature_Normal(GdkCircleFeature feature, kPoint3d64f* normal);

kEndHeader()

#include <Gdk/Tools/GdkCircleFeature.x.h>

#endif
