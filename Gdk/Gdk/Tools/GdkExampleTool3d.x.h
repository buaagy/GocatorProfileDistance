#ifndef GDK_EXAMPLE_TOOL_3D_X_H
#define GDK_EXAMPLE_TOOL_3D_X_H

kBeginHeader()

#define GDK_EXAMPLE_TOOL_3D_NAME        "ExampleTool3d"

typedef struct
{
    GdkToolClass base;
} GdkExampleTool3dClass;

kDeclareClass(Gdk, GdkExampleTool3d, GdkTool)

#define GdkExampleTool3d_Cast_(CONTEXT)    kCastClass_(GdkExampleTool3d, CONTEXT)

GdkFx(const kChar*) GdkExampleTool3d_VName();
GdkFx(kStatus) GdkExampleTool3d_VDescribe(GdkToolInfo info);

GdkFx(kStatus) GdkExampleTool3d_VInit(GdkExampleTool3d info, kType type, kAlloc alloc);
GdkFx(kStatus) GdkExampleTool3d_VRelease(GdkExampleTool3d info);
GdkFx(kStatus) GdkExampleTool3d_VNewToolConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleTool3d_VNewMeasurementConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkExampleTool3d_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleTool3d_VStart(GdkExampleTool3d tool);
GdkFx(kStatus) GdkExampleTool3d_VStop(GdkExampleTool3d tool);
GdkFx(kStatus) GdkExampleTool3d_VProcess(GdkExampleTool3d tool, GdkToolInput input, GdkToolOutput output);

GdkFx(kStatus) GdkExampleTool3d_Process(GdkExampleTool3d tool, GdkToolInput input, kPoint3d64f* min, kPoint3d64f* max, k8u* averageIntensity);
GdkFx(kStatus) GdkExampleTool3d_Render(GdkExampleTool3d tool, GdkToolInput input, GdkToolOutput output);
GdkFx(kStatus) GdkExampleTool3d_RenderTest(GdkExampleTool3d tool, GdkToolInput input, GdkToolOutput output);

kEndHeader()

#endif
