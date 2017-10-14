/** 
 * @file    GdkGraphic.x.h
 *
 * @internal
 * Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_GRAPHIC_X_H
#define GDK_GRAPHIC_X_H

#include <kFireSync/Data/kGraphic.h>
#include <kApi/Data/kMath.h>
#include <kApi/Data/kArrayList.h>

kBeginHeader()

kDeclareClass(Gdk, GdkGraphicLineSet, kObject)
typedef struct GdkGraphicLineSetClass
{
    kObjectClass base;
    k32f width;
    kColor colour;
    kArrayList set; //of kPoint3d32f
}GdkGraphicLineSetClass;

#define GdkGraphicLineSet_Cast_(CONTEXT)                kCastClass_(GdkGraphicLineSet, CONTEXT)

GdkFx(kStatus) GdkGraphicLineSet_Init(GdkGraphicLineSet set, kType classType, 
                                    k32f width, kColor colour, 
                                    const kPoint3d32f* points, kSize count,
                                    kAlloc allocator);
GdkFx(kStatus) GdkGraphicLineSet_VInitClone(GdkGraphicLineSet dest, 
                                          GdkGraphicLineSet source, 
                                          kAlloc allocator);
GdkFx(kStatus) GdkGraphicLineSet_VRelease(GdkGraphicLineSet set);
GdkFx(kSize) GdkGraphicLineSet_VSize(GdkGraphicLineSet set);

kDeclareClass(Gdk, GdkGraphicPointSet, kObject)
typedef struct GdkGraphicPointSetClass
{
    kObjectClass base;
    k32f size;
    kMarkerShape shape;
    kColor colour;
    kArrayList set; //of type kPoint3d32f
}GdkGraphicPointSetClass;

#define GdkGraphicPointSet_Cast_(CONTEXT)                kCastClass_(GdkGraphicPointSet, CONTEXT)

GdkFx(kStatus) GdkGraphicPointSet_Init(GdkGraphicPointSet set, 
                                     kType classType,
                                     k32f size, kMarkerShape shape, 
                                     kColor colour, 
                                     const kPoint3d32f* points, 
                                     kSize count, kAlloc allocator);
GdkFx(kStatus) GdkGraphicPointSet_VInitClone(GdkGraphicPointSet dest, 
                                           GdkGraphicPointSet source, 
                                           kAlloc allocator);
GdkFx(kStatus) GdkGraphicPointSet_VRelease(GdkGraphicPointSet set);
GdkFx(kSize) GdkGraphicPointSet_VSize(GdkGraphicPointSet set);

kDeclareClass(Gdk, GdkGraphic, kObject)

typedef struct
{
    kObjectClass base; 
    GdkDataType srcDataType;
    kArrayList lineSetList;   //GdkGraphicLineSet
    kArrayList pointSetList;  //GdkGraphicPointSet
    kArrayList anchorRegions; //GdkGraphicAnchorRegion
} GdkGraphicClass; 

#define GdkGraphic_Cast_(CONTEXT)                kCastClass_(GdkGraphic, CONTEXT)

GdkFx(kStatus) GdkGraphic_Init(GdkGraphic graphic, kType classType, kAlloc allocator);
GdkFx(kStatus) GdkGraphic_VInitClone(GdkGraphic graphic, GdkGraphic source, kAlloc allocator); 
GdkFx(kStatus) GdkGraphic_Release(GdkGraphic graphic); 

GdkFx(kStatus) GdkGraphic_VRelease(GdkGraphic graphic);
GdkFx(kSize) GdkGraphic_VSize(GdkGraphic graphic);


GdkFx(GdkDataType) GdkGraphic_SourceDataType(GdkGraphic graphic);
GdkFx(kStatus) GdkGraphic_SetSourceDataType(GdkGraphic graphic, GdkDataType srcDataType);

/**
* Returns an arraylist of anchor regions for Flash renderer data serialization
*
* @private              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @return              An arraylist of GdkGraphicAnchorRegion
*/
GdkFx(kArrayList) GdkGraphic_AnchorRegionList(GdkGraphic graphic);


kEndHeader()

#endif
