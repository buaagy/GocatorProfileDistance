/** 
 * @file    GdkGraphicAnchorRegion2d.h
 * @brief   Declares the GdkGraphicAnchorRegion2d class. 
 *
 * @internal
 * Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_GRAPHIC_ANCHOR_REGION_2D_H
#define GDK_GRAPHIC_ANCHOR_REGION_2D_H

#include <Gdk/GdkDef.h>
#include <Gdk/Data/GdkGraphicAnchorRegion.h>

kBeginHeader()

/**
 * @class       GdkGraphicAnchorRegion2d
 * @extends     kObject
 * @ingroup     Gdk-Data
 * @brief       Represents a collection of vector anchorRegions.
 */
 typedef GdkGraphicAnchorRegion GdkGraphicAnchorRegion2d;

/** 
 * Constructs a anchorRegion object. 
 *
 * @public                  @memberof GdkGraphicAnchorRegion2d
 * @param   anchorRegion    Destination for the constructed object handle.  
 * @param   allocator       Memory allocator (or kNULL for default). 
 * @return                  Operation status. 
 */
GdkFx(kStatus) GdkGraphicAnchorRegion2d_Construct(GdkGraphicAnchorRegion2d* anchorRegion, kObject allocator);

/**
* Sets the center point of a 2d Region
*
* @public                       @memberof GdkGraphicAnchorRegion2d
* @param   anchorRegion     GdkGraphicAnchorRegion2d object.
* @param   x                X coordinate of center point
* @param   z                Z coordinate of center point
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion2d_SetCenter(GdkGraphicAnchorRegion2d anchorRegion, k64f x, k64f z);

/**
* Sets the dimensions of a 2d Region
*
* @public                   @memberof GdkGraphicAnchorRegion2d
* @param   anchorRegion     GdkGraphicAnchorRegion2d object.
* @param   width            width of region
* @param   height           height of region
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion2d_SetDimensions(GdkGraphicAnchorRegion2d anchorRegion, k64f width, k64f height);

/**
* Sets the rotation angle (about Y Axis) of the Region
*
* @public                   @memberof GdkGraphicAnchorRegion2d
* @param   anchorRegion     GdkGraphicAnchorRegion2d object.
* @param   angle            angle of rotation about Y axis
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion2d_SetYAngle(GdkGraphicAnchorRegion2d anchorRegion, k64f angle);

/**
* Sets the anchor region using a standard region struct.
*
* @public                   @memberof GdkGraphicAnchorRegion2d
* @param   anchorRegion     GdkGraphicAnchorRegion2d object.
* @param   region           Pointer to region value.
* @return                   Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion2d_SetRegion(GdkGraphicAnchorRegion2d anchorRegion, const GdkRegionXZ64f* region);

kEndHeader()
#include <Gdk/Data/GdkGraphicAnchorRegion2d.x.h>

#endif
