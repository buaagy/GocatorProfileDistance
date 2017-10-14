#ifndef GSA_ASM_H
#define GSA_ASM_H

#include <GoSensorAppLib/GsaDef.h>

kBeginHeader()

GsaFx(kStatus) GsaAsm_Construct(kAssembly* assembly);

GsaFx(kStatus) GoSensorAppLib_Main();

kEndHeader()

#include <GoSensorAppLib/GsaAsm.x.h>

#endif
