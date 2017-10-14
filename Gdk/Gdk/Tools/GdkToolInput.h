/**
* @file    GdkToolInput.h
* @brief   Declares the GdkToolInput and related classes.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_TOOL_INPUT_H
#define GDK_TOOL_INPUT_H

#include <Gdk/GdkDef.h>
#include <Gdk/Tools/GdkFeature.h>
#include <Gdk/Utils/GdkDataInfo.h>

kBeginHeader()

/**
* Represents a tool input collection.
*
* @class       GdkToolInput
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkToolInput;
kDeclareClass(Gdk, GdkToolInput, kObject)
kDeclareValue(Gdk, GdkInputItemClass, kValue)
kDeclareValue(Gdk, GdkToolFeatureInputItem, kValue)

/**
* Represents a tool input item.
*
* @class       GdkInputItem
* @ingroup     Gdk-Tools
*/
typedef kPointer GdkInputItem;

/**
* @struct  GdkFrameInfo
* @extends kValue
* @ingroup Gdk-Tools
* @brief   Represents acquisition metadata associated with a data message.
*/

typedef struct
{
	k64u frame;				///< Frame index of message data (counts up from zero).
	k64u time;				///< Timestamp corresponding to message data (us).
	k64s encoder;			///< Encoder value corresponding to message data (encoder ticks). 
	k64s encoderIndex;		///< Encoder value at time of most recent encoder snapshot signal (encoder ticks).
	k64u digitalInputStatus;/**<
	* Bit mask containing frame information:
	*
	* - Bit 0: Represents sensor digital input state.
	* - Bit 4: Represents Master digital input state.
	* - Bits 8 and 9: Represents inter-frame digital pulse trigger
	(Master digital input if a Master is connected, otherwise
	sensor digital input. Value is cleared after each frame
	and clamped at 3 if more than 3 pulses are received).
	*/
} GdkFrameInfo;

/**
* Returns the item correspoding to the selected data source.
*
* If the selected source has multiple items (e.g. top and bottom), this will return
* the first item (e.g. the top).
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @return               Selected input item.
*/
GdkFx(GdkInputItem) GdkToolInput_Selected(GdkToolInput input);

/**
* Returns the secondary item correspoding to the selected data source.
*
* If the selected source has multiple items (e.g. top and bottom), this will return
* the second item (e.g. the bottom). Otherwise kNULL is returned.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @return               Secondary selected input item.
*/
GdkFx(GdkInputItem) GdkToolInput_SelectedSec(GdkToolInput input);

/**
* Finds an input item by data source.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @param    source      Data source.
* @return               Input item corresponding to source. kNULL if not found.
*/
GdkFx(GdkInputItem) GdkToolInput_Find(GdkToolInput input, GdkDataSource source);

/**
* Returns the anchoring position for the input.
*
* If anchoring is not enabled for an axis, the value for that axis is 0.0.
* A value may be k64F_NULL if anchoring fails for that axis.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @return               Pointer to anchoring position.
*/
GdkFx(const kPoint3d64f*) GdkToolInput_AnchorPosition(GdkToolInput input);

/**
* Returns true if the tool is anchored in the specified component.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @param    component   Component of the anchor input to return.
* @return               Component is set.
*/
GdkFx(kBool) GdkToolInput_IsAnchorSet(GdkToolInput input, GdkAnchorParam component);

/**
* Returns true if the tool is anchored in any component.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @return               Any component is set.
*/
GdkFx(kBool) GdkToolInput_IsAnyAnchorSet(GdkToolInput input);

/**
* Returns the a component of the anchor input.
*
* If the tool is not anchored in the specified component (e.g. Z angle anchoring
* is not used), then k64F_NULL is returned.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @param    component   Component of the anchor input to return.
* @return               Value of the specified component.
*/
GdkFx(k64f) GdkToolInput_AnchorValue(GdkToolInput input, GdkAnchorParam component);

/**
* Returns the position of the feature providing the anchoring value.
*
* Sometimes it is useful to know the position of the feature providing the anchoring
* value for a given dimension. This function will return the position if the source tool
* provides it for the anchor source measurement. All built-in tools provide the position,
* as well as GDK-based tools that use GdkToolInput_SetMeasurementPosition to set it.
*
* @public               @memberof GdkToolInput
* @param    input       Input collection.
* @param    component   Component of the anchor input for which to return the position.
* @return               Value of the specified component.
*/
GdkFx(const kPoint3d64f*) GdkToolInput_AnchorFeaturePosition(GdkToolInput input, GdkAnchorParam component);

/**
* Returns the static data source descriptor for the item.
*
* @public               @memberof GdkInputItem
* @param    input       Input item.
* @return               Data source descriptor.
*/
GdkFx(GdkDataInfo) GdkInputItem_Info(GdkInputItem input);

/**
* Returns the frame information for the item.
*
* @public               @memberof GdkInputItem
* @param    input       Input item.
* @return               Frame Information.
*/
GdkFx(GdkFrameInfo) GdkInputItem_FrameInfo(GdkInputItem input);

/**
* Returns data offset for the item.
*
* The data offset should be added to any calculation turning integers or
* array indices into real world units (mm). Note that the offset can change
* from frame-to-frame due to features such as part detection.
*
* @public               @memberof GdkInputItem
* @param    input       Input item.
* @return               Data offset.
*/
GdkFx(const kPoint3d64f*) GdkInputItem_Offset(GdkInputItem input);

/**
* Returns transformation matrix of the item in global space.
*
* @public               @memberof GdkInputItem
* @param    input       Input item.
* @return               Transformation matrix in global space.
*/
GdkFx(const GdkTransform3d*) GdkInputItem_GlobalMatrix(GdkInputItem input);

/**
* Represents a range input.
*
* @class        GdkRangeInput
* @extends      GdkInputItem
* @ingroup      Gdk-Tools
*/
typedef kPointer GdkRangeInput;

/**
* Returns the range value.
*
* @public               @memberof GdkRangeInput
* @param    input       Input item.
* @return               Range value.
*/
GdkFx(k16s) GdkRangeInput_Range(GdkRangeInput input);

/**
* Returns the intensity value.
*
* @public               @memberof GdkRangeInput
* @param    input       Input item.
* @return               Intensity value.
*/
GdkFx(k8u) GdkRangeInput_Intensity(GdkRangeInput input);

/**
* Represents a resampled profile input.
*
* @class        GdkProfileInput
* @extends      GdkInputItem
* @ingroup      Gdk-Tools
*/
typedef kPointer GdkProfileInput;

/**
* Returns the number of points.
*
* @public               @memberof GdkProfileInput
* @param    input       Input item.
* @return               Point count.
*/
GdkFx(kSize) GdkProfileInput_Count(GdkProfileInput input);

/**
* Returns the range values.
*
* @public               @memberof GdkProfileInput
* @param    input       Input item.
* @return               Range values.
*/
GdkFx(const k16s*) GdkProfileInput_Ranges(GdkProfileInput input);

/**
* Returns the intensity values.
*
* @public               @memberof GdkProfileInput
* @param    input       Input item.
* @return               Intensity values.
*/
GdkFx(const k8u*) GdkProfileInput_Intensities(GdkProfileInput input);

/**
* Represents an unresampled profile input.
*
* @class        GdkRawProfileInput
* @extends      GdkInputItem
* @ingroup      Gdk-Tools
*/
typedef kPointer GdkRawProfileInput;

/**
* Returns the number of points.
*
* @public               @memberof GdkRawProfileInput
* @param    input       Input item.
* @return               Point count.
*/
GdkFx(kSize) GdkRawProfileInput_Count(GdkRawProfileInput input);

/**
* Returns the range values.
*
* @public               @memberof GdkRawProfileInput
* @param    input       Input item.
* @return               Range values.
*/
GdkFx(const GdkPointXZ16s*) GdkRawProfileInput_Ranges(GdkRawProfileInput input);

/**
* Returns the intensity values.
*
* @public               @memberof GdkRawProfileInput
* @param    input       Input item.
* @return               Intensity values.
*/
GdkFx(const k8u*) GdkRawProfileInput_Intensities(GdkRawProfileInput input);

/**
* Represents a resampled surface input.
*
* @class        GdkSurfaceInput
* @extends      GdkInputItem
* @ingroup      Gdk-Tools
*/
typedef kPointer GdkSurfaceInput;

/**
* Returns the number of columns.
*
* @public               @memberof GdkSurfaceInput
* @param    input       Input item.
* @return               Column count.
*/
GdkFx(kSize) GdkSurfaceInput_ColumnCount(GdkSurfaceInput input);

/**
* Returns the number of rows.
*
* @public               @memberof GdkSurfaceInput
* @param    input       Input item.
* @return               Row count.
*/
GdkFx(kSize) GdkSurfaceInput_RowCount(GdkSurfaceInput input);

/**
* Returns the range values at a specified row.
*
* @public               @memberof GdkSurfaceInput
* @param    input       Input item.
* @param    row         Row index.
* @return               Range values.
*/
GdkFx(const k16s*) GdkSurfaceInput_RangeRowAt(GdkSurfaceInput input, kSize row);

/**
* Returns the intensity values at a specified row.
*
* @public               @memberof GdkSurfaceInput
* @param    input       Input item.
* @param    row         Row index.
* @return               Intensity values.
*/
GdkFx(const k8u*) GdkSurfaceInput_IntensityRowAt(GdkSurfaceInput input, kSize row);

/**
* Returns the Gdk feature class object at the specified index.
*
* @public               @memberof GdkSurfaceInput
* @param    input       Input item.
* @param    index       Row index.
* @return               Intensity values.
*/
GdkFx(GdkFeature) GdkToolInput_FeatureAt(GdkToolInput input, kSize index);

kEndHeader()

#endif 
