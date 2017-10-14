#ifndef GSA_ASM_X_H
#define GSA_ASM_X_H

#include <kApi/kApiDef.h>

kBeginHeader()

#define GSA_VERSION     kVersion_Stringify_(GOCATOR_VERSION_MAJOR, GOCATOR_VERSION_MINOR, GOCATOR_VERSION_RELEASE, GOCATOR_VERSION_BUILD)

kDeclareAssembly(Gsa, GsaAsm)

kEndHeader()

#endif
