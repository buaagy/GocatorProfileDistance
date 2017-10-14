#ifndef GDK_EXAMPLE_TOOL_X_H
#define GDK_EXAMPLE_TOOL_X_H

kBeginHeader()

#define GDK_EXAMPLE_TOOL_NAME        "ExampleTool"

typedef struct
{
    GdkToolClass base;
} GdkExampleToolClass;

kDeclareClass(Gdk, GdkExampleTool, GdkTool)

#define GdkExampleTool_Cast_(CONTEXT)    kCastClass_(GdkExampleTool, CONTEXT)

GdkFx(const kChar*) GdkExampleTool_VName();
GdkFx(kStatus) GdkExampleTool_VDescribe(GdkToolInfo info);

GdkFx(kStatus) GdkExampleTool_DescribeV0(GdkToolInfo info);
GdkFx(kStatus) GdkExampleTool_DescribeV1(GdkToolInfo info);
GdkFx(kStatus) GdkExampleTool_DescribeV2(GdkToolInfo info);

GdkFx(kStatus) GdkExampleTool_VInit(GdkExampleTool info, kType type, kAlloc alloc);
GdkFx(kStatus) GdkExampleTool_VRelease(GdkExampleTool info);
GdkFx(kStatus) GdkExampleTool_VNewToolConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleTool_VNewMeasurementConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkExampleTool_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleTool_VStart(GdkExampleTool tool);
GdkFx(kStatus) GdkExampleTool_VStop(GdkExampleTool tool);
GdkFx(kStatus) GdkExampleTool_VProcess(GdkExampleTool tool, GdkToolInput input, GdkToolOutput output);

kEndHeader()

#endif
