/**
* @file    GdkGraphicAnchorRegion3d.x.h
*
* @internal
* Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_GRAPHIC_ANCHOR_REGION_3D_X_H
#define GDK_GRAPHIC_ANCHOR_REGION_3D_X_H

#include <kApi/Data/kMath.h>
#include <kApi/Data/kArrayList.h>

#include <Gdk/GdkDef.h>

kBeginHeader()

typedef struct
{
    GdkGraphicAnchorRegionClass base;
    k64f x, y, z;
    k64f width, height, depth;
    k64f angle; //About Z Axis
} GdkGraphicAnchorRegion3dClass;

kDeclareClass(Gdk, GdkGraphicAnchorRegion3d, GdkGraphicAnchorRegion)

#define GdkGraphicAnchorRegion3d_Cast_(CONTEXT)                kCastClass_(GdkGraphicAnchorRegion3d, CONTEXT)

GdkFx(kStatus) GdkGraphicAnchorRegion3d_Init(GdkGraphicAnchorRegion3d graphic, kType classType, kAlloc allocator);
GdkFx(kStatus) GdkGraphicAnchorRegion3d_Release(GdkGraphicAnchorRegion3d graphic);

GdkFx(kStatus) GdkGraphicAnchorRegion3d_VRelease(GdkGraphicAnchorRegion3d graphic);
GdkFx(kStatus) GdkGraphicAnchorRegion3d_VSerialize(GdkGraphicAnchorRegion3d anchorRegion, kSerializer serializer);



kEndHeader()

#endif
