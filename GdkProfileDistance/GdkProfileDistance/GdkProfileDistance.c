#include <GdkProfileDistance/GdkProfileDistance.h>
#include <math.h>

kBeginClass(Tool, GdkProfileDistance, GdkTool)
	kAddVMethod(GdkProfileDistance, kObject, VRelease)
	kAddVMethod(GdkProfileDistance, GdkTool, VInit)
	kAddVMethod(GdkProfileDistance, GdkTool, VDescribe)
	kAddVMethod(GdkProfileDistance, GdkTool, VUpdateConfig)
	kAddVMethod(GdkProfileDistance, GdkTool, VStart)
	kAddVMethod(GdkProfileDistance, GdkTool, VStop)
	kAddVMethod(GdkProfileDistance, GdkTool, VProcess)
kEndClass()

//#define DEBUG

#ifdef WIN32
#ifdef DEBUG

#include <windows.h>
kChar debugLine[10240];

kStatus GdkProfileDistance_Trace(const kChar* format, ...)
{
	kStatus status = kOK;

	kVarArgList argList;
	kVarArgList_Start_(argList, format);
	{
		status = kStrPrintvf(debugLine, 10240, format, argList);
	}
	kVarArgList_End_(argList);
	OutputDebugStringA(debugLine);

	return status;
}

#endif
#endif

ToolFx(kStatus) GdkProfileDistance_VDescribe(GdkToolInfo toolInfo)
{
	GdkParamsInfo paramInfo;
	GdkMeasurementInfo mmtInfo;
	GdkRegionXZ64f topRegion = { -9, -9, 18, 18 };
	GdkRegionXZ64f bottomRegion = { -10, -10, 20, 20 };

	kCheck(GdkToolInfo_SetTypeName(toolInfo, GDK_PROFILE_DISTANCE_TOOL_NAME));
	kCheck(GdkToolInfo_SetLabel(toolInfo, GDK_PROFILE_DISTANCE_TOOL_LABEL));

	kCheck(GdkToolInfo_SetSourceType(toolInfo, GDK_DATA_TYPE_UNIFORM_PROFILE));
	kCheck(GdkToolInfo_AddSourceOption(toolInfo, GDK_DATA_SOURCE_TOP));
	kCheck(GdkToolInfo_AddSourceOption(toolInfo, GDK_DATA_SOURCE_BOTTOM));
	kCheck(GdkToolInfo_AddSourceOption(toolInfo, GDK_DATA_SOURCE_TOP_BOTTOM));

	//add anchor
	kCheck(GdkToolInfo_EnableAnchoring(toolInfo, GDK_ANCHOR_PARAM_X, kTRUE));
	kCheck(GdkToolInfo_EnableAnchoring(toolInfo, GDK_ANCHOR_PARAM_Z, kTRUE));

	paramInfo = GdkToolInfo_Params(toolInfo);

	//add regions
	kCheck(GdkParamsInfo_AddProfileRegion(paramInfo, "TopRegion", "Top Region", &topRegion, kNULL));
	kCheck(GdkParamsInfo_AddProfileRegion(paramInfo, "BottomRegion", "Bottom Region", &bottomRegion, kNULL));

	//add measurements
	kCheck(GdkToolInfo_AddMeasurement(toolInfo, "Distance", &mmtInfo));
	kCheck(GdkMeasurementInfo_SetLabel(mmtInfo, "Distance"));
	kCheck(GdkMeasurementInfo_SetValueType(mmtInfo, GDK_MEASUREMENT_VALUE_TYPE_VALUE));

	return kOK;
}

ToolFx(kStatus) GdkProfileDistance_VInit(GdkProfileDistance tool, kType type, kAlloc alloc)
{
	GdkProfileDistanceClass* obj = (GdkProfileDistanceClass*)tool;

	kCheck(GdkTool_VInit(tool, type, alloc));
	kInitFields_(GdkProfileDistance, tool);

	return kOK;
}

ToolFx(kStatus) GdkProfileDistance_VRelease(GdkProfileDistance tool)
{
	GdkProfileDistanceClass* obj = GdkProfileDistance_Cast_(tool);

	return GdkTool_VRelease(tool);
}

ToolFx(kStatus) GdkProfileDistance_VUpdateConfig(const GdkToolEnv* env, GdkToolCfg toolConfig)
{
	return kOK;
}

ToolFx(kStatus) GdkProfileDistance_VStart(GdkProfileDistance tool)
{
	GdkProfileDistanceClass* obj = GdkProfileDistance_Cast_(tool);
	GdkToolCfg config = GdkTool_Config(tool);
	GdkParams params = GdkToolCfg_Parameters(config);

	obj->topRegion = *GdkParam_AsProfileRegion(GdkParams_Find(params, "TopRegion"));
	obj->bottomRegion = *GdkParam_AsProfileRegion(GdkParams_Find(params, "BottomRegion"));

	return kOK;
}

ToolFx(kStatus) GdkProfileDistance_VStop(GdkProfileDistance tool)
{
	return kOK;
}

ToolFx(kStatus) GdkProfileDistance_VProcess(GdkProfileDistance tool, GdkToolInput input, GdkToolOutput output)
{
	GdkProfileDistanceClass* obj = GdkProfileDistance_Cast_(tool);
	GdkInputItem topItem, bottomItem;
	GdkDataInfo topItemInfo, bottomItemInfo;
	const kPoint3d64f* anchor = GdkToolInput_AnchorPosition(input);

	kSize topWidthFull, bottomWidthFull;
	k64f topScaleX, topScaleZ, topOffsetX, topOffsetZ;
	k64f bottomScaleX, bottomScaleZ, bottomOffsetX, bottomOffsetZ;

	const k16s *topData, *bottomData;
	GdkRegionXZ64f topRegion = { k64F_NULL, k64F_NULL, k64F_NULL, k64F_NULL };
	GdkRegionXZ64f bottomRegion = { k64F_NULL, k64F_NULL, k64F_NULL, k64F_NULL };
	k32s i, j;
	k32s topMinX, topMaxX, topMinZ, topMaxZ;
	k32s bottomMinX, bottomMaxX, bottomMinZ, bottomMaxZ;
	k16s zValue;
	kSize count = 0;
	k64f thickness = 0, distanceMin, distanceTemp, distanceX, distanceZ;
	kPoint3d64f topPoint, bottomPoint;
	kStatus exception = kOK;

	topItem = GdkToolInput_Find(input, GDK_DATA_SOURCE_TOP);
	bottomItem = GdkToolInput_Find(input, GDK_DATA_SOURCE_BOTTOM);
	if (!topItem || !bottomItem)
	{
		return kERROR_PARAMETER;
	}
	topItemInfo = GdkInputItem_Info(topItem);
	bottomItemInfo = GdkInputItem_Info(bottomItem);

	//get profile data
	topData = GdkProfileInput_Ranges(topItem);
	bottomData = GdkProfileInput_Ranges(bottomItem);

	//get the width, scale and offset
	topWidthFull = GdkProfileInput_Count(topItem);
	topScaleX = GdkDataInfo_Scale(topItemInfo)->x;
	topScaleZ = GdkDataInfo_Scale(topItemInfo)->z;
	topOffsetX = GdkInputItem_Offset(topItem)->x;
	topOffsetZ = GdkInputItem_Offset(topItem)->z;
	bottomWidthFull = GdkProfileInput_Count(bottomItem);
	bottomScaleX = GdkDataInfo_Scale(bottomItemInfo)->x;
	bottomScaleZ = GdkDataInfo_Scale(bottomItemInfo)->z;
	bottomOffsetX = GdkInputItem_Offset(bottomItem)->x;
	bottomOffsetZ = GdkInputItem_Offset(bottomItem)->z;
	//GdkProfileDistance_Trace("TopWidthFull:%d, TopScaleX:%f, TopScaleZ:%f, TopOffsetX:%f, TopOffsetZ:%f\r\n", topWidthFull, topScaleX, topScaleZ, topOffsetX, topOffsetZ);
	//GdkProfileDistance_Trace("BottomWidthFull:%d, BottomScaleX:%f, BottomScaleZ:%f, BottomOffsetX:%f, BottomOffsetZ:%f\r\n", bottomWidthFull, bottomScaleX, bottomScaleZ, bottomOffsetX, bottomOffsetZ);

	kPoint3d_Init_(&topPoint, 0, 0, 0);
	kPoint3d_Init_(&bottomPoint, 0, 0, 0);

	kTry
	{
		//get the region with anchor
		topRegion = obj->topRegion;
		topRegion.x += anchor->x;
		topRegion.z += anchor->z;
		bottomRegion = obj->bottomRegion;
		bottomRegion.x += anchor->x;
		bottomRegion.z += anchor->z;

		//get start and end index
		topMinX = (k32s)(kMax_(0, (topRegion.x - topOffsetX) / topScaleX));
		topMaxX = (k32s)(kMin_(topWidthFull, (topRegion.x + topRegion.width - topOffsetX) / topScaleX));
		topMinZ = (k32s)((topRegion.z - topOffsetZ) / topScaleZ);
		topMaxZ = (k32s)((topRegion.z + topRegion.height - topOffsetZ) / topScaleZ);
		bottomMinX = (k32s)(kMax_(0, (bottomRegion.x - bottomOffsetX) / bottomScaleX));
		bottomMaxX = (k32s)(kMin_(bottomWidthFull, (bottomRegion.x + bottomRegion.width - bottomOffsetX) / bottomScaleX));
		bottomMinZ = (k32s)((bottomRegion.z - bottomOffsetZ) / bottomScaleZ);
		bottomMaxZ = (k32s)((bottomRegion.z + bottomRegion.height - bottomOffsetZ) / bottomScaleZ);
		//GdkProfileDistance_Trace("TopMinX:%d, TopMaxX:%d, TopMinZ:%d, TopMaxZ:%d\r\n", topMinX, topMaxX, topMinZ, topMaxZ);
		//GdkProfileDistance_Trace("BottomMinX:%d, BottomMaxX:%d, BottomMinZ:%d, BottomMaxZ:%d\r\n", bottomMinX, bottomMaxX, bottomMinZ, bottomMaxZ);

		for (i = topMinX; i <= topMaxX; i += 10)
		{
			zValue = topData[i];
			if (zValue == k16S_NULL || zValue < topMinZ || zValue > topMaxZ)
				continue;
			topPoint.x = i * topScaleX + topOffsetX;
			topPoint.z = zValue * topScaleZ + topOffsetZ;
			distanceMin = k64F_MAX;
			for (j = bottomMinX; j <= bottomMaxX; j++)
			{
				zValue = bottomData[j];
				if (zValue == k16S_NULL || zValue < bottomMinZ || zValue > bottomMaxZ)
					continue;
				bottomPoint.x = j * bottomScaleX + bottomOffsetX;
				bottomPoint.z = zValue * bottomScaleZ + bottomOffsetZ;
				distanceX = topPoint.x - bottomPoint.x;
				distanceZ = topPoint.z - bottomPoint.z;
				distanceTemp = distanceX * distanceX + distanceZ * distanceZ;
				if (distanceTemp < distanceMin)
				{
					distanceMin = distanceTemp;
				}
			}
			if (distanceMin != k64F_MAX)
			{
				thickness += sqrt(distanceMin);
				count++;
			}
		}

		//set the results
		if (count != 0)
		{
			thickness /= count;
			kTest(GdkToolOutput_SetResult(output, GDK_PROFILE_DISTANCE_MEASUREMENT_DISTANCE, thickness, GDK_MEASUREMENT_OK));
		}
		else
		{
			kTest(GdkToolOutput_SetResult(output, GDK_PROFILE_DISTANCE_MEASUREMENT_DISTANCE, 0.0, GDK_MEASUREMENT_ERROR_VALUE));
		}
	}
	kCatchEx(&exception)
	{
		kEndCatchEx(exception);
	}
	kFinallyEx
	{
		kEndFinallyEx();
	}

	return kOK;
}
