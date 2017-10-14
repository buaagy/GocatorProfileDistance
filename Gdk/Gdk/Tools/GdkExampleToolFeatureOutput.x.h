#ifndef GDK_EXAMPLE_TOOL_FEATUREOUTPUT_X_H
#define GDK_EXAMPLE_TOOL_FEATUREOUTPUT_X_H

kBeginHeader()

#define GDK_EXAMPLE_TOOL_FEATURE_OUTPUT_NAME        "ExampleToolFeatureOutput"

typedef struct
{
    GdkToolClass base;
} GdkExampleToolFeatureOutputClass;

kDeclareClass(Gdk, GdkExampleToolFeatureOutput, GdkTool)

#define GdkExampleToolFeatureOutput_Cast_(CONTEXT)    kCastClass_(GdkExampleToolFeatureOutput, CONTEXT)

GdkFx(const kChar*) GdkExampleToolFeatureOutput_VName();
GdkFx(kStatus) GdkExampleToolFeatureOutput_VDescribe(GdkToolInfo info);

GdkFx(kStatus) GdkExampleToolFeatureOutput_DescribeV0(GdkToolInfo info);
GdkFx(kStatus) GdkExampleToolFeatureOutput_DescribeV1(GdkToolInfo info);
GdkFx(kStatus) GdkExampleToolFeatureOutput_DescribeV2(GdkToolInfo info);

GdkFx(kStatus) GdkExampleToolFeatureOutput_VInit(GdkExampleToolFeatureOutput info, kType type, kAlloc alloc);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VRelease(GdkExampleToolFeatureOutput info);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VNewToolConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VNewMeasurementConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VStart(GdkExampleToolFeatureOutput tool);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VStop(GdkExampleToolFeatureOutput tool);
GdkFx(kStatus) GdkExampleToolFeatureOutput_VProcess(GdkExampleToolFeatureOutput tool, GdkToolInput input, GdkToolOutput output);

kEndHeader()

#endif
