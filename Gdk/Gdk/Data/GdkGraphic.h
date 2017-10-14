/** 
 * @file    GdkGraphic.h
 * @brief   Declares the GdkGraphic class. 
 *
 * @internal
 * Copyright (C) 2008-2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_GRAPHIC_H
#define GDK_GRAPHIC_H

#include <Gdk/GdkDef.h>
#include <Gdk/Data/GdkGraphicAnchorRegion.h>
#include <Gdk/Data/GdkGraphicAnchorRegion2d.h>
#include <Gdk/Data/GdkGraphicAnchorRegion3d.h>
#include <kFireSync/Data/kGraphic.h>

kBeginHeader()

/**
 * @class       GdkGraphicLineSet
 * @extends     kObject
 * @ingroup     Gdk-Data
 * @brief       Represents a set of 2d polylines.
 */
typedef kObject GdkGraphicLineSet;

/** 
 * Creates a set of polylines.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         Handle to hold the newly constructed line set.
 * @param   width       Line width.
 * @param   colour      Line colour.
 * @param   points      Array of line points (if null, will allocate a buffer without copying points).    
 * @param   count       Count of points.    
 * @param   allocator   Memory allocator to use in constructing the object.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicLineSet_Construct(GdkGraphicLineSet* set, k32f width, kColor colour, const kPoint3d32f* points, kSize count, kAlloc allocator);

/** 
 * Returns an array list of points.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         The graphic line set object.
 * @return              The array list of points.
 */
GdkFx(kArrayList) GdkGraphicLineSet_PointList(GdkGraphicLineSet set);

/** 
 * Returns the configured width of the line set.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         The graphic line set object.
 * @return              The line set width.
 */
GdkFx(k32f) GdkGraphicLineSet_Width(GdkGraphicLineSet set);

/** 
 * Sets the width of the line set.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         The graphic line set object.
 * @param   width       The desired width of the line set.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicLineSet_SetWidth(GdkGraphicLineSet set, k32f width);

/** 
 * Returns the configured colour of the line set.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         The graphic line set object.
 * @return              The line set colour.
 */
GdkFx(kColor) GdkGraphicLineSet_Colour(GdkGraphicLineSet set);

/** 
 * Sets the colour of the line set.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         The graphic line set object.
 * @param   colour       The desired colour of the line set.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicLineSet_SetColour(GdkGraphicLineSet set, kColor colour);

/**
 * @class       GdkGraphicPointSet
 * @extends     kObject
 * @ingroup     GoSensor-Data
 * @brief       Represents a set of points.
 */
typedef kObject GdkGraphicPointSet;

/** 
 * Creates a set of points.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         Pointer to assign the constructed point set to.
 * @param   size        Size of the points to be drawn.
 * @param   shape       Shape of the points to be drawn.
 * @param   colour      Colour of the points to be drawn.
 * @param   points      Array of points (if null, will allocate a buffer without copying points).    
 * @param   count       Count of points.    
 * @param   allocator   Memory allocator to use in constructing the object.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicPointSet_Construct(GdkGraphicPointSet* set, k32f size, kMarkerShape shape, kColor colour, const kPoint3d32f* points, kSize count, kAlloc allocator);

/** 
 * Returns an array list of points.
 *
 * @public              @memberof GdkGraphicLineSet
 * @param   set         The graphic line set object.
 * @return              The array list of points.
 */
GdkFx(kArrayList) GdkGraphicPointSet_PointList(GdkGraphicPointSet set);

/** 
 * Returns the configured size of the point set.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         The graphic point set object.
 * @return              The point set size.
 */
GdkFx(k32f) GdkGraphicPointSet_Size(GdkGraphicPointSet set);

/** 
 * Sets the size of the point set.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         The graphic point set object.
 * @param   size        The desired size of the point set.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicPointSet_SetSize(GdkGraphicPointSet set, k32f size);

/** 
 * Returns the configured shape of the point set.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         The graphic point set object.
 * @return              The point set shape.
 */
GdkFx(kMarkerShape) GdkGraphicPointSet_Shape(GdkGraphicPointSet set);

/** 
 * Sets the shape of the point set.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         The graphic point set object.
 * @param   shape       The desired shape of the point set.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicPointSet_SetShape(GdkGraphicPointSet set, kMarkerShape shape);

/** 
 * Returns the configured colour of the point set.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         The graphic point set object.
 * @return              The point set colour.
 */
GdkFx(kColor) GdkGraphicPointSet_Colour(GdkGraphicPointSet set);

/** 
 * Sets the colour of the point set.
 *
 * @public              @memberof GdkGraphicPointSet
 * @param   set         The graphic point set object.
 * @param   colour      The desired colour of the point set.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphicPointSet_SetColour(GdkGraphicPointSet set, kColor colour);

/**
 * @class       GdkGraphic
 * @extends     kObject
 * @ingroup     Gdk-Data
 * @brief       Represents a collection of vector graphics.
 */
typedef kObject GdkGraphic;

/** 
 * Constructs a graphic object. 
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Destination for the constructed object handle.  
 * @param   allocator   Memory allocator (or kNULL for default). 
 * @return              Operation status. 
 */
GdkFx(kStatus) GdkGraphic_Construct(GdkGraphic* graphic, kObject allocator);

/** 
 * Returns an arraylist of lines for Flash renderer data serialization
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.   
 * @return              An arraylist of GdkGraphicLineSet
 */
GdkFx(kArrayList) GdkGraphic_LineSetList(GdkGraphic graphic);

/** 
 * Adds a line set to the GdkGraphic instance.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @param   set         The line set to be added.
 * @return              Operation status. 
 */
GdkFx(kStatus) GdkGraphic_AddLineSet(GdkGraphic graphic, GdkGraphicLineSet set);

/** 
 * Removes a line set from the GdkGraphic instance.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @param   index       The index of the line set to remove.
 * @return              Operation status. 
 */
GdkFx(kStatus) GdkGraphic_RemoveLineSet(GdkGraphic graphic, kSize index);

/** 
 * Returns the number of line sets currently in the graphic object.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @return              The current number of line sets in the graphic object.
 */
GdkFx(kSize) GdkGraphic_LineSetCount(GdkGraphic graphic);

/** 
 * Retrieves a line set at the specified index. 
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @param   index       The index of the line set to remove.
 * @return              A graphic line set or kNULL if the index is invalid.
 */
GdkFx(GdkGraphicLineSet) GdkGraphic_LineSetAt(GdkGraphic graphic, kSize index);

/** 
 * Returns an arraylist of points for Flash renderer data serialization
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.   
 * @return              An arraylist of GdkGraphicPointSet
 */
GdkFx(kArrayList) GdkGraphic_PointSetList(GdkGraphic graphic);

/** 
 * Adds a point set to the GdkGraphic instance.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @param   set         The point set to be added.
 * @return              Operation status. 
 */
GdkFx(kStatus) GdkGraphic_AddPointSet(GdkGraphic graphic, GdkGraphicPointSet set);

/** 
 * Returns the number of point sets currently in the graphic object.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @return              The current number of point sets in the graphic object.
 */
GdkFx(kSize) GdkGraphic_PointSetCount(GdkGraphic graphic);

/** 
 * Retrieves a point set at the specified index. 
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @param   index       The index of the point set to remove.
 * @return              A graphic point set or kNULL if the index is invalid.
 */
GdkFx(GdkGraphicPointSet) GdkGraphic_PointSetAt(GdkGraphic graphic, kSize index);

/** 
 * Removes a point set from the GdkGraphic instance.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.
 * @param   index       The index of the point set to remove.
 * @return              Operation status. 
 */
GdkFx(kStatus) GdkGraphic_RemovePointSet(GdkGraphic graphic, kSize index);

/** 
 * Adds a point set to the point set list.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     Graphic object.   
 * @param   set         A GdkGraphicPointSet to add;
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphic_AddPointSet(GdkGraphic graphic, GdkGraphicPointSet set);

/**
* Adds an anchor region to the GdkGraphic instance.
*
* @public              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @param   region      The anchor region to be added.
* @return              Operation status.
*/
GdkFx(kStatus) GdkGraphic_AddAnchorRegion(GdkGraphic graphic, GdkGraphicAnchorRegion region);

/**
* Returns the number of anchor regions currently in the graphic object.
*
* @public              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @return              The current number of anchor regions in the graphic object.
*/
GdkFx(kSize) GdkGraphic_AnchorRegionCount(GdkGraphic graphic);

/**
* Retrieves an anchor region at the specified index.
*
* @public              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @param   index       The index of the anchor region to remove.
* @return              A graphic anchor region or kNULL if the index is invalid.
*/
GdkFx(GdkGraphicAnchorRegion) GdkGraphic_AnchorRegionAt(GdkGraphic graphic, kSize index);

/**
* Removes an anchor region from the GdkGraphic instance.
*
* @public              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @param   index       The index of the anchor region to remove.
* @return              Operation status.
*/
GdkFx(kStatus) GdkGraphic_RemoveAnchorRegion(GdkGraphic graphic, kSize index);

/**
* Adds an anchor region to the point set list.
*
* @public              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @param   region      A GdkGraphicAnchorRegion to add;
* @return              Operation status.
*/
GdkFx(kStatus) GdkGraphic_AddAnchorRegion(GdkGraphic graphic, GdkGraphicAnchorRegion region);

/**
* Adds a graphic item to the graphic object. The item must be one of the supported types.
*
* @public              @memberof GdkGraphic
* @param   graphic     Graphic object.
* @param   item        A supported graphic item type (e.g. GdkGraphicPointSet).
* @return              Operation status.
*/
GdkFx(kStatus) GdkGraphic_AddItem(GdkGraphic graphic, kObject item);

/**
 * Generates a kGraphic object for use with functions which may require a kGraphic.
 * 
 * @public              @memberof GdkGraphic
 * @param   object      GdkGraphic object to derive a kGraphic from.
 * @param   graphic     kGraphic object.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphic_GeneratekGraphic(GdkGraphic object, kGraphic* graphic);

/**
 * Given a serializer, the contents of the line and point lists are written 
 * in a predefined format.
 *
 * @public              @memberof GdkGraphic
 * @param   graphic     GdkGraphic object.
 * @param   serializer  A kSerializer object with which to populate.
 * @return              Operation status.
 */
GdkFx(kStatus) GdkGraphic_Serialize(GdkGraphic graphic, kSerializer serializer);

/**
* Given a serializer, a null (empty) graphics object is written in a predefined
* format
*
* @public              @memberof GdkGraphic
* @param   serializer  A kSerializer object with which to populate.
* @return              Operation status.
*/
GdkFx(kStatus) GdkGraphic_SerializeNull(kSerializer serializer);

kEndHeader()
#include <Gdk/Data/GdkGraphic.x.h>

#endif
