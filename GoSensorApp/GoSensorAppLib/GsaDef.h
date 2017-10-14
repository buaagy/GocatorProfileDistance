#ifndef GSA_DEF_H
#define GSA_DEF_H

#include <kApi/kApiDef.h>

kBeginHeader()

#if defined(GO_SENSOR_APP_LIB_EMIT)
#   define GsaFx(TYPE)                  kExportFx(TYPE)
#   define GsaDx(TYPE)                  kExportDx(TYPE)
#else
#   define GsaFx(TYPE)                  kImportFx(TYPE)
#   define GsaDx(TYPE)                  kImportDx(TYPE)
#endif

kStatus kCall GoSensorAppLib_ConstructAssembly(kAssembly* userAsm);

kEndHeader()

#endif
