#ifndef GDK_EXAMPLE_TOOL_FEATUREINPUT_X_H
#define GDK_EXAMPLE_TOOL_FEATUREINPUT_X_H

kBeginHeader()

#define GDK_EXAMPLE_TOOL_FEATURE_INPUT_NAME        "ExampleToolFeatureInput"

typedef struct
{
    GdkToolClass base;
} GdkExampleToolFeatureInputClass;

kDeclareClass(Gdk, GdkExampleToolFeatureInput, GdkTool)

#define GdkExampleToolFeatureInput_Cast_(CONTEXT)    kCastClass_(GdkExampleToolFeatureInput, CONTEXT)

GdkFx(const kChar*) GdkExampleToolFeatureInput_VName();
GdkFx(kStatus) GdkExampleToolFeatureInput_VDescribe(GdkToolInfo info);

GdkFx(kStatus) GdkExampleToolFeatureInput_DescribeV0(GdkToolInfo info);
GdkFx(kStatus) GdkExampleToolFeatureInput_DescribeV1(GdkToolInfo info);
GdkFx(kStatus) GdkExampleToolFeatureInput_DescribeV2(GdkToolInfo info);

GdkFx(kStatus) GdkExampleToolFeatureInput_VInit(GdkExampleToolFeatureInput info, kType type, kAlloc alloc);
GdkFx(kStatus) GdkExampleToolFeatureInput_VRelease(GdkExampleToolFeatureInput info);
GdkFx(kStatus) GdkExampleToolFeatureInput_VNewToolConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleToolFeatureInput_VNewMeasurementConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkExampleToolFeatureInput_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkExampleToolFeatureInput_VStart(GdkExampleToolFeatureInput tool);
GdkFx(kStatus) GdkExampleToolFeatureInput_VStop(GdkExampleToolFeatureInput tool);
GdkFx(kStatus) GdkExampleToolFeatureInput_VProcess(GdkExampleToolFeatureInput tool, GdkToolInput input, GdkToolOutput output);

kEndHeader()

#endif
