#ifndef GDK_EXAMPLE_TOOL_FEATUREOUTPUTSURFACE_X_H
#define GDK_EXAMPLE_TOOL_FEATUREOUTPUTSURFACE_X_H

kBeginHeader()

#define GDK_EXAMPLE_TOOL_FEATURE_OUTPUT_SURFACE_NAME        "ExampleToolFeatureOutputSurface"

typedef struct
{
    GdkToolClass base;
} GdkExampleToolFeatureOutputSurfaceClass;

kDeclareClass(Gdk, GdkExampleToolFeatureOutputSurface, GdkTool)

#define GdkExampleToolFeatureOutputSurface_Cast_(CONTEXT)    kCastClass_(GdkExampleToolFeatureOutputSurface, CONTEXT)

GdkFx(const kChar*) GdkExampleToolFeatureOutputSurface_VName();
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VDescribe(GdkToolInfo info);

GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VInit(GdkExampleToolFeatureOutputSurface info, kType type, kAlloc alloc);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VRelease(GdkExampleToolFeatureOutputSurface info);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VNewToolConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VNewMeasurementConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VStart(GdkExampleToolFeatureOutputSurface tool);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VStop(GdkExampleToolFeatureOutputSurface tool);
GdkFx(kStatus) GdkExampleToolFeatureOutputSurface_VProcess(GdkExampleToolFeatureOutputSurface tool, GdkToolInput input, GdkToolOutput output);

kEndHeader()

#endif
