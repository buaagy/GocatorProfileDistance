/** 
 * @file    GdkLineFeature.h
 *
 * @internal
 * Copyright (C) 2016 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#ifndef GDK_LINE_FEATURE_H
#define GDK_LINE_FEATURE_H

#include <Gdk/Tools/GdkFeature.h>

kBeginHeader()

/**
* Describes a GDK line feature.
*
* @class       GdkLineFeature
* @extends     GdkFeature
* @ingroup     Gdk-Tools
*/
typedef GdkFeature GdkLineFeature;
kDeclareClass(Gdk, GdkLineFeature, GdkFeature)

/**
* Sets the point of the line feature.
*
* @public               @memberof GdkLineFeature
* @param    feature     Line feature object.
* @param    point       Reference to point of line to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkLineFeature_SetPoint(GdkLineFeature feature, const kPoint3d64f* point);

/**
* Returns the point of the line feature.
*
* @public               @memberof GdkLineFeature
* @param    feature     Line feature object.
* @return               Reference to point of line feature.
*/
GdkFx(const kPoint3d64f*) GdkLineFeature_Point(GdkLineFeature feature);

/**
* Sets the point of the line feature.
*
* @public               @memberof GdkLineFeature
* @param    feature     Line feature object.
* @param    direction   Reference to direction vector of line to set.
* @return               Operation status.
*/
GdkFx(kStatus) GdkLineFeature_SetDirection(GdkLineFeature feature, const kPoint3d64f* direction);

/**
* Returns the direction of the line feature.
*
* @public               @memberof GdkLineFeature
* @param    feature     Line feature object.
* @param    direction   Reference to direction vector of line.
* @return               Operation status.
*/
GdkFx(kStatus) GdkLineFeature_Direction(GdkLineFeature feature, kPoint3d64f* direction);

kEndHeader()

#include <Gdk/Tools/GdkLineFeature.x.h>

#endif
