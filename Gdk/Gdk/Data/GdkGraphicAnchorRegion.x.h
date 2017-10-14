/** 
 * @file    GdkGraphicAnchorRegion.x.h
 *
 * @internal
 * Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_GRAPHIC_ANCHOR_REGION_X_H
#define GDK_GRAPHIC_ANCHOR_REGION_X_H

#include <kApi/Data/kMath.h>
#include <kApi/Data/kArrayList.h>

#include <Gdk/GdkDef.h>

kBeginHeader()

typedef struct
{
    kObjectClass base; 
    GdkGraphicAnchorRegionType type;
} GdkGraphicAnchorRegionClass; 

typedef struct GdkGraphicAnchorRegionVTable
{
    kObjectVTable base;
    kStatus(kCall* VSerialize)(GdkGraphicAnchorRegion anchorRegion, kSerializer serializer);
} GdkGraphicAnchorRegionVTable;

kDeclareVirtualClass(Gdk, GdkGraphicAnchorRegion, kObject)

#define GdkGraphicAnchorRegion_Cast_(CONTEXT)                kCastClass_(GdkGraphicAnchorRegion, CONTEXT)
#define GdkGraphicAnchorRegion_VTable_(OBJ)                  kCastVTable_(GdkGraphicAnchorRegion, OBJ)

#define GDK_GRAPHIC_ANCHOR_REGION_SERIALIZE_SCALE 1000000

GdkFx(kStatus) GdkGraphicAnchorRegion_Construct(GdkGraphicAnchorRegion* anchorRegion, kObject allocator);
GdkFx(kStatus) GdkGraphicAnchorRegion_Init(GdkGraphicAnchorRegion anchorRegion, kType classType, kAlloc allocator);
GdkFx(kStatus) GdkGraphicAnchorRegion_Release(GdkGraphicAnchorRegion anchorRegion); 

GdkFx(kStatus) GdkGraphicAnchorRegion_VRelease(GdkGraphicAnchorRegion anchorRegion);
GdkFx(kStatus) GdkGraphicAnchorRegion_VSerialize(GdkGraphicAnchorRegion anchorRegion, kSerializer serializer);

/**
* Given a serializer, the contents of the line and point lists are written
* in a predefined format.
*
* @private                 @memberof GdkGraphicAnchorRegion
* @param   anchorRegion    GdkGraphicAnchorRegion object.
* @param   serializer      A kSerializer object with which to populate.
* @return                  Operation status.
*/
GdkFx(kStatus) GdkGraphicAnchorRegion_Serialize(GdkGraphicAnchorRegion anchorRegion, kSerializer serializer);


kEndHeader()

#endif
