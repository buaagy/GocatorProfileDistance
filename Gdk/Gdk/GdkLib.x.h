#ifndef GDK_LIB_X_H
#define GDK_LIB_X_H

#include <kApi/kApiDef.h>

kBeginHeader()

#define GSBASE_VERSION   kVersion_Stringify_(1, 0, 0, 0)

kDeclareAssembly(Gdk, Gdk)

typedef kStatus (kCall *GdkLibLogFx)(const kChar* msg, va_list args);

GdkFx(GdkLibLogFx) GdkLib_LogFx();
GdkFx(kStatus) GdkLib_SetLogFx(GdkLibLogFx function);

kEndHeader()

#endif
