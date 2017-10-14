/**
* @file    GdkGraphicAnchorRegion3d.h
* @brief   Declares the GdkGraphicAnchorRegion3d class.
*
* @internal
* Copyright (C) 3008-3015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_GRAPHIC_ANCHOR_REGION_3D_H
#define GDK_GRAPHIC_ANCHOR_REGION_3D_H

#include <Gdk/GdkDef.h>
#include <Gdk/Data/GdkGraphicAnchorRegion.h>

kBeginHeader()

/**
* @class       GdkGraphicAnchorRegion3d
* @extends     kObject
* @ingroup     Gdk-Data
* @brief       Represents a collection of vector anchorRegions.
*/
typedef GdkGraphicAnchorRegion GdkGraphicAnchorRegion3d;

/**
* Constructs a anchorRegion object.
*
* @public                  @memberof GdkGraphicAnchorRegion3d
* @param   anchorRegion    Destination for the constructed object handle.
* @param   allocator       Memory allocator (or kNULL for default).
* @return                  Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion3d_Construct(GdkGraphicAnchorRegion3d* anchorRegion, kObject allocator);

/**
* Sets the center point of a 3d Region
*
* @public                       @memberof GdkGraphicAnchorRegion3d
* @param   anchorRegion     GdkGraphicAnchorRegion3d object.
* @param   x                X coordinate of center point
* @param   y                Y coordinate of center point
* @param   z                Z coordinate of center point
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion3d_SetCenter(GdkGraphicAnchorRegion3d anchorRegion, k64f x, k64f y, k64f z);

/**
* Sets the dimensions of a 3d Region
*
* @public                   @memberof GdkGraphicAnchorRegion3d
* @param   anchorRegion     GdkGraphicAnchorRegion3d object.
* @param   width            width of region
* @param   height           height of region
* @param   depth            depth of region
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion3d_SetDimensions(GdkGraphicAnchorRegion3d anchorRegion, k64f width, k64f height, k64f depth);

/**
* Sets the rotation angle (about Z Axis) of the Region
*
* @public                   @memberof GdkGraphicAnchorRegion3d
* @param   anchorRegion     GdkGraphicAnchorRegion3d object.
* @param   angle            angle of rotation about Z axis
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion3d_SetZAngle(GdkGraphicAnchorRegion3d anchorRegion, k64f angle);

/**
* Sets the anchor region using a standard region struct.
*
* @public                   @memberof GdkGraphicAnchorRegion3d
* @param   anchorRegion     GdkGraphicAnchorRegion3d object.
* @param   region           Pointer to region value.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion3d_SetRegion(GdkGraphicAnchorRegion3d anchorRegion, const GdkRegion3d64f* region);

kEndHeader()
#include <Gdk/Data/GdkGraphicAnchorRegion3d.x.h>

#endif
