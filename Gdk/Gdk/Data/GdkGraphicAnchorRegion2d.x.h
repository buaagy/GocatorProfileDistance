/** 
 * @file    GdkGraphicAnchorRegion2d.x.h
 *
 * @internal
 * Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_GRAPHIC_ANCHOR_REGION_2D_X_H
#define GDK_GRAPHIC_ANCHOR_REGION_2D_X_H

#include <kApi/Data/kMath.h>
#include <kApi/Data/kArrayList.h>

#include <Gdk/GdkDef.h>

kBeginHeader()

typedef struct
{
    GdkGraphicAnchorRegionClass base;
    k64f x, z;
    k64f width, height;
    k64f angle; //About y Axis
} GdkGraphicAnchorRegion2dClass; 

kDeclareClass(Gdk, GdkGraphicAnchorRegion2d, GdkGraphicAnchorRegion)

#define GdkGraphicAnchorRegion2d_Cast_(CONTEXT)                kCastClass_(GdkGraphicAnchorRegion2d, CONTEXT)

GdkFx(kStatus) GdkGraphicAnchorRegion2d_Init(GdkGraphicAnchorRegion2d graphic, kType classType, kAlloc allocator);
GdkFx(kStatus) GdkGraphicAnchorRegion2d_Release(GdkGraphicAnchorRegion2d graphic); 

GdkFx(kStatus) GdkGraphicAnchorRegion2d_VRelease(GdkGraphicAnchorRegion2d graphic);
GdkFx(kStatus) GdkGraphicAnchorRegion2d_VSerialize(GdkGraphicAnchorRegion2d anchorRegion, kSerializer serializer);



kEndHeader()

#endif
