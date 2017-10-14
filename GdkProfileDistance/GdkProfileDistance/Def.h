#ifndef TOOL_DEF_H
#define TOOL_DEF_H

#include <kApi/kApiDef.h>

kBeginHeader()

#if defined(TOOL_EMIT)
#    define ToolFx(TYPE)            kInFx(TYPE)
#    define ToolDx(TYPE)            kInDx(TYPE)
#else
#    define ToolFx(TYPE)            kInFx(TYPE)        
#    define ToolDx(TYPE)            kInDx(TYPE)        
#endif

kEndHeader()

#endif
