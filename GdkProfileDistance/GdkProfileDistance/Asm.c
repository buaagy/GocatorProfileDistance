#include <GdkProfileDistance/Asm.h>
#include <GdkProfileDistance/GdkProfileDistance.h>
#include <Gdk/GdkLib.h>
#include <GoSensor/Version.h>
#include <GoSensorAppLib/GsaDef.h>
#include <GoSensorAppLib/GsaAsm.h>

kBeginAssembly(Tool, ToolAsm, TOOL_VERSION, GOCATOR_VERSION)
    kAddDependency(GdkLib)
	kAddType(GdkProfileDistance)
kEndAssembly()

#if !defined(GO_GDK_DYNAMIC)
kStatus kCall GoSensorAppLib_ConstructAssembly(kAssembly* userAsm)
{
    return ToolAsm_Construct(userAsm);
}
#endif
