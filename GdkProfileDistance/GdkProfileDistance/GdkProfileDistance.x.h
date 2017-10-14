#ifndef TOOL_GDK_PROFILE_DISTANCE_TOOL_Z_H
#define TOOL_GDK_PROFILE_DISTANCE_TOOL_Z_H

kBeginHeader()

#define GDK_PROFILE_DISTANCE_TOOL_NAME        "GdkProfileDistance"
#define GDK_PROFILE_DISTANCE_TOOL_LABEL       "Profile Distance"

typedef enum GdkProfileDistanceMeasurement
{
	GDK_PROFILE_DISTANCE_MEASUREMENT_DISTANCE = 0,
	GDK_PROFILE_DISTANCE_MEASUREMENT_COUNT
} GdkProfileDistanceMeasurement;

typedef struct
{
    GdkToolClass base;
	GdkRegionXZ64f topRegion, bottomRegion;
} GdkProfileDistanceClass;

kDeclareClass(Tool, GdkProfileDistance, GdkTool)

#define GdkProfileDistance_Cast_(CONTEXT)    kCastClass_(GdkProfileDistance, CONTEXT)

ToolFx(kStatus) GdkProfileDistance_VDescribe(GdkToolInfo info);
ToolFx(kStatus) GdkProfileDistance_VInit(GdkProfileDistance tool, kType type, kAlloc alloc);
ToolFx(kStatus) GdkProfileDistance_VRelease(GdkProfileDistance tool);
ToolFx(kStatus) GdkProfileDistance_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
ToolFx(kStatus) GdkProfileDistance_VStart(GdkProfileDistance tool);
ToolFx(kStatus) GdkProfileDistance_VStop(GdkProfileDistance tool);
ToolFx(kStatus) GdkProfileDistance_VProcess(GdkProfileDistance tool, GdkToolInput input, GdkToolOutput output);

kEndHeader()

#endif
