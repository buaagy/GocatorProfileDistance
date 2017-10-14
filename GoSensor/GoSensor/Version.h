#ifndef GS_VERSION_H
#define GS_VERSION_H

#include <kApi/kApiDef.h>

#define GOCATOR_VERSION_MAJOR 4
#define GOCATOR_VERSION_MINOR 6
#define GOCATOR_VERSION_RELEASE 7
#define GOCATOR_VERSION_BUILD 126

#define GOCATOR_VERSION             kVersion_Stringify_(GOCATOR_VERSION_MAJOR, GOCATOR_VERSION_MINOR, GOCATOR_VERSION_RELEASE, GOCATOR_VERSION_BUILD)
#define GOCATOR_VERSION_NUMBER      kVersion_Create_(GOCATOR_VERSION_MAJOR, GOCATOR_VERSION_MINOR, GOCATOR_VERSION_RELEASE, GOCATOR_VERSION_BUILD)

#endif
