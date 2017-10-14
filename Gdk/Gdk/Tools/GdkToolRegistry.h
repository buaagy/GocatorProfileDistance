#ifndef GDK_TOOL_REGISTRY_H
#define GDK_TOOL_REGISTRY_H

#include <Gdk/GdkDef.h>
#include <Gdk/Tools/GdkToolInfo.h>
#include <Gdk/Tools/GdkTool.h>

kBeginHeader()

typedef kObject GdkToolRegistry;

typedef k32u GdkToolRegistryInvalidReason;

#define GDK_TOOL_REGISTRY_INVALID_NAME       (1)
#define GDK_TOOL_REGISTRY_INVALID_DUPLICATE  (2)

GdkFx(kStatus) GdkToolRegistry_Add(GdkToolInfo info);
GdkFx(kStatus) GdkToolRegistry_DiscoverCustomTools();

GdkFx(kStatus) GdkToolRegistry_Clear();

GdkFx(kStatus) GdkToolRegistry_Find(const kChar* typeName, GdkToolInfo* info);
GdkFx(kStatus) GdkToolRegistry_TypeFromName(const kChar* typeName, kType* type);

GdkFx(kSize) GdkToolRegistry_InfoCount();
GdkFx(GdkToolInfo) GdkToolRegistry_InfoAt(kSize index);

GdkFx(GdkToolInfo) GdkToolRegistry_ToolInfo(const kChar* typeName);
GdkFx(GdkMeasurementInfo) GdkToolRegistry_MeasurementInfo(const kChar* toolType, const kChar* version, const kChar* measurementType);
GdkFx(GdkFeatureInfo) GdkToolRegistry_FeatureInfo(const kChar* toolType, const kChar* version, const kChar* featureType);

GdkFx(kPointer) GdkToolRegistry_FirstInvalid();
GdkFx(kPointer) GdkToolRegistry_NextInvalid(kPointer item);

GdkFx(GdkToolInfo) GdkToolRegistry_InvalidInfo(kPointer item);
GdkFx(GdkToolRegistryInvalidReason) GdkToolRegistry_InvalidReason(kPointer item);

kEndHeader()

#include <Gdk/Tools/GdkToolRegistry.x.h>

#endif 
