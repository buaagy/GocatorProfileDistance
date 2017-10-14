#ifndef GDK_TOOL_X_H
#define GDK_TOOL_X_H

#include <kApi/kObject.h>
#include <kApi/Data/kArrayList.h>
#include <kApi/Data/kMap.h>
#include <kApi/Data/kString.h>
#include <Gdk/Config/GdkToolCfg.h>
#include <Gdk/Config/GdkMeasurementCfg.h>
#include <Gdk/Utils/GdkUtils.h>

kBeginHeader()

typedef struct GdkToolVTable
{
    kObjectVTable base;
    const kChar* (kCall* VName)();
    kStatus (kCall* VDescribe)(GdkToolInfo info);
    kStatus (kCall* VInit)(GdkTool info, kType type, kAlloc alloc);
    kStatus (kCall* VNewToolConfig)(const GdkToolEnv* env, GdkToolCfg toolConfig);
    kStatus (kCall* VNewMeasurementConfig)(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
    kStatus (kCall* VNewFeatureConfig)(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
    kStatus (kCall* VUpdateConfig)(const GdkToolEnv* env, GdkToolCfg toolConfig);
    kStatus (kCall* VStart)(GdkTool tool);
    kStatus (kCall* VStop)(GdkTool tool);
    kStatus (kCall* VProcess)(GdkTool tool, GdkToolInput input, GdkToolOutput output);
    kBool (kCall* VIsVisible)(const GdkToolEnv* env);
} GdkToolVTable;

typedef struct GdkToolClass
{
    kObjectClass base;

    GdkToolCfg config;
    GdkSensorInfo sensorInfo;
    kMap featureInputNameToIndexMap;
    
    kBool diagnosticsRouted;

    GdkToolInput currentInput;
} GdkToolClass;

kDeclareVirtualClass(Gdk, GdkTool, kObject)

#define GdkTool_Cast_(CONTEXT)                   kCastClass_(GdkTool, CONTEXT)
#define GdkTool_VTable_(CONTEXT)                 kCastVTable_(GdkTool, CONTEXT)

GdkFx(const kChar*) GdkTool_VName();
GdkFx(kStatus) GdkTool_VDescribe(GdkToolInfo info);

GdkFx(kStatus) GdkTool_VInit(GdkTool tool, kType type, kAlloc allocator);
GdkFx(kStatus) GdkTool_VRelease(GdkTool tool);

GdkFx(kStatus) GdkTool_VNewToolConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkTool_VNewMeasurementConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkTool_VNewFeatureConfig(const GdkToolEnv* env, GdkToolCfg toolConfig, GdkFeatureCfg featureConfig);
GdkFx(kStatus) GdkTool_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkTool_VStart(GdkTool tool);
GdkFx(kStatus) GdkTool_VStop(GdkTool tool);
GdkFx(kStatus) GdkTool_VProcess(GdkTool tool, GdkToolInput input, GdkToolOutput output);
GdkFx(kBool) GdkTool_VIsVisible(const GdkToolEnv* env);

// Called by the framework

GdkFx(kStatus) GdkTool_EnumerateTypes(kArrayList types);
GdkFx(const kChar*) GdkTool_Name(kType type);
GdkFx(kStatus) GdkTool_Describe(kType type, GdkToolInfo info);
GdkFx(kStatus) GdkTool_InitToolConfig(kType type, const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kStatus) GdkTool_InitMeasurementConfig(kType type, const GdkToolEnv* env, GdkToolCfg toolConfig, GdkMeasurementCfg measurementConfig);
GdkFx(kStatus) GdkTool_InitFeatureConfig(kType type, const GdkToolEnv* env, GdkToolCfg toolConfig, GdkFeatureCfg featureConfig);
GdkFx(kStatus) GdkTool_OnConfigUpdate(kType type, const GdkToolEnv* env, GdkToolCfg toolConfig);
GdkFx(kBool) GdkTool_IsVisible(kType type, const GdkToolEnv* env);

GdkFx(kStatus) GdkTool_Construct(GdkTool* tool, kType type, kAlloc alloc);

GdkFx(kStatus) GdkTool_Init(GdkTool tool, kType type, kAlloc allocator);

GdkFx(kStatus) GdkTool_SetConfig(GdkTool tool, GdkToolCfg config);
GdkFx(kStatus) GdkTool_SetSensorInfo(GdkTool tool, GdkSensorInfo info);
GdkFx(kStatus) GdkTool_AddInputFeatureMap(GdkTool tool, kString* nameStr, kSize* index);

GdkFx(kStatus) GdkTool_Start(GdkTool tool);
GdkFx(kStatus) GdkTool_Stop(GdkTool tool);
GdkFx(kStatus) GdkTool_Process(GdkTool tool, GdkToolInput input, GdkToolOutput output);
GdkFx(kStatus) GdkTool_Run(GdkTool tool, GdkToolInput input, GdkToolOutput output);

GdkFx(kStatus) GdkTool_SetDiagnosticsRouted(GdkTool tool, kBool enable);

GdkFx(kStatus) GdkTool_DrawAnchoredRegions(GdkTool tool, GdkToolInput input, GdkToolOutput output);
GdkFx(kStatus) GdkTool_DrawAnchorPoints(GdkTool tool, GdkToolInput input, GdkToolOutput output);

GdkFx(kStatus) GdkTool_DrawAnchoredRegionXZ(GdkTool tool, GdkToolInput input, const GdkRegionXZ64f* region, GdkGraphicAnchorRegion* graphic);
GdkFx(kStatus) GdkTool_DrawAnchoredRegion3d(GdkTool tool, GdkToolInput input, const GdkRegion3d64f* region, GdkGraphicAnchorRegion* graphic);
GdkFx(kStatus) GdkTool_AddGraphicItemToOutputs(GdkTool tool, GdkToolOutput output, kObject graphicItem);

GdkFx(kStatus) GdkTool_ApplyAnchorToRegionXZ(GdkTool tool, GdkToolInput input, const GdkRegionXZ64f* originalRegion, GdkRegionXZ64f* newRegion);
GdkFx(kStatus) GdkTool_ApplyAnchorToRegion3d(GdkTool tool, GdkToolInput input, const GdkRegion3d64f* originalRegion, GdkRegion3d64f* newRegion);

/**
* Returns true if this tool has any routed diagnostic outputs.
*
* @public               @memberof GdkTool
* @param   tool         Tool object.
* @return               if this tool has any routed diagnostic outputs.
*/
GdkFx(kBool) GdkTool_DiagnosticsRouted(GdkTool tool);

kEndHeader()

#endif
