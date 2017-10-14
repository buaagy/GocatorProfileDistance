/**
* @file    GdkToolOutput.h
* @brief   Declares the GdkToolOutput class.
*
* Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_TOOL_OUTPUT_H
#define GDK_TOOL_OUTPUT_H

#include <Gdk/GdkDef.h>
#include <Gdk/Data/GdkGraphic.h>

kBeginHeader()

/**
* Represents a tool output collection.
*
* @class       GdkToolOutput
* @extends     kObject
* @ingroup     Gdk-Tools
*/
typedef kObject GdkToolOutput;
kDeclareClass(Gdk, GdkToolOutput, kObject)
kDeclareValue(Gdk, GdkToolMeasurementOutputItem, kValue)
kDeclareValue(Gdk, GdkToolFeatureOutputItem, kValue)
kDeclareValue(Gdk, GdkToolDiagnosticOutputItem, kValue)

/**
* Sets the measurement output at a specified index.
*
* @public               @memberof GdkToolOutput
* @param    output      Output object.
* @param    index       Measurement index within the tool.
* @param    value       Output value.
* @param    decision    Output decision.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolOutput_SetResult(GdkToolOutput output, kSize index, k64f value, GdkMeasurementDecision decision);

/**
* If the measurement value is a component of the position of a feature, use this
* function to associate the full position with the measurement.
*
* For a measurement that may be used as an anchor input to other tools, the
* position of the associated feature should be provided so downstream tools
* can use it for visualization or more advanced processing techniques.
*
* @public               @memberof GdkToolOutput
* @param    output      Output object.
* @param    index       Measurement index within the tool.
* @param    position    Position.
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolOutput_SetResultPosition(GdkToolOutput output, kSize index, const kPoint3d64f* position);

/**
* Sets the measurement rendering at a specified index.
*
* @public               @memberof GdkToolOutput
* @param    output      Output object.
* @param    index       Measurement index within the tool.
* @param    graphic     GdkGraphic object (ownership is transferred).
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolOutput_SetRendering(GdkToolOutput output, kSize index, GdkGraphic graphic);

/**
* Sets the feature rendering at a specified index.
*
* @public               @memberof GdkToolOutput
* @param    output      Output object.
* @param    index       Feature index within the tool.
* @param    graphic     GdkGraphic object (ownership is transferred).
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolOutput_SetFeatureRendering(GdkToolOutput output, kSize index, GdkGraphic graphic);

/**
* Sets the diagnostic output at a specified index.
*
* @public               @memberof GdkToolOutput
* @param    output      Output object.
* @param    index       diagnostic output index within the tool. (The place in order the diagnostic output was added to the tool).
* @param    msg         An object that implements kMsgSet (ownership is transferred).
* @return               Operation status.
*/
GdkFx(kStatus) GdkToolOutput_SetDiagnostic(GdkToolOutput output, kSize index, kMsgSet msg);

/**
* Gets the feature class object at the specified index.
*
* @public               @memberof GdkToolOutput
* @param    output      Output object.
* @param    index       Index of the output object to retrieve.
* @return               GdkFeature class object.
*/
GdkFx(GdkFeature) GdkToolOutput_FeatureAt(GdkToolOutput output, kSize index);

kEndHeader()

#endif 
