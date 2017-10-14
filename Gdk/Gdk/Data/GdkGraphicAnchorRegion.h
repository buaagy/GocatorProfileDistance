/** 
 * @file    GdkGraphicAnchorRegion.h
 * @brief   Declares the GdkGraphicAnchorRegion class. 
 *
 * @internal
 * Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_GRAPHIC_ANCHOR_REGION_H
#define GDK_GRAPHIC_ANCHOR_REGION_H

#include <Gdk/GdkDef.h>

kBeginHeader()

/**
 * @class       GdkGraphicAnchorRegion
 * @extends     kObject
 * @ingroup     Gdk-Data
 * @brief       Represents a collection of vector anchorRegions.
 */
typedef kObject GdkGraphicAnchorRegion;

/**
 * Returns the type of the Anchor Region
 *
 * @public                  @memberof GdkGraphicAnchorRegion
 * @param   anchorRegion    GdkGraphicAnchorRegion object.
 * @return                  GdkGraphicAnchorRegionType
 */
GdkFx(GdkGraphicAnchorRegionType) GdkGraphicAnchorRegion_Type(GdkGraphicAnchorRegion anchorRegion);


kEndHeader()
#include <Gdk/Data/GdkGraphicAnchorRegion.x.h>

#endif
