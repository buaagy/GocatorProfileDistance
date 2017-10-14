#ifndef GDK_UTILS_H
#define GDK_UTILS_H

#include <Gdk/GdkDef.h>
#include <kApi/Data/kArrayList.h>
#include <kApi/Data/kString.h>

kBeginHeader()

GdkFx(kStatus) GdkUtils_FormatCsv(kArrayList list, kString str);
GdkFx(kStatus) GdKUtils_ParseCsv(kArrayList list, const kChar* text);

GdkFx(kStatus) GdkUtils_ApplyAnchorToRegion3d(const GdkRegion3d64f* regionIn,
    const kPoint3d64f* anchorX,
    const kPoint3d64f* anchorY,
    const kPoint3d64f* anchorZ,
    k64f anchorZAngle,
    GdkRegion3d64f* anchoredRegion);

kEndHeader()

#endif
