#ifndef GDK_TOOL_REGISTRY_X_H
#define GDK_TOOL_REGISTRY_X_H

#include <Gdk/Tools/GdkToolRegistry.h>
#include <kApi/Data/kArrayList.h>
#include <kApi/Data/kMap.h>
#include <Gdk/Tools/GdkMeasurementInfo.z.h>
#include <Gdk/Config/GdkParamsInfo.z.h>

kBeginHeader()

#define GDK_TOOL_REGISTRY_KEY        kText256

typedef struct GdkToolRegistryInvalid
{
    GdkToolRegistryInvalidReason reason;
} GdkToolRegistryInvalid;

kDeclareValue(Gdk, GdkToolRegistryInvalid, kValue)

typedef struct
{
    kArrayList completeList;

    // These containers do not own items.
    kArrayList validList;
    kMap validMap; // GDK_TOOL_REGISTRY_KEY, GdkToolInfo
    kMap invalidMap; // GdkToolInfo, GdkToolRegistryInvalid
} GdkToolRegistryStatic;

kDeclareStaticClass(Gdk, GdkToolRegistry)

#define GdkToolRegistry_Static_()        ((GdkToolRegistryStatic*)kStaticOf_(GdkToolRegistry))

GdkFx(kStatus) GdkToolRegistry_InitStatic();
GdkFx(kStatus) GdkToolRegistry_ReleaseStatic();

GdkFx(kStatus) GdkToolRegistry_CheckNewInfoName(GdkToolInfo info, kBool* pass);
GdkFx(kStatus) GdkToolRegistry_CheckNewInfoDuplicate(GdkToolInfo info, kBool* pass);

GdkFx(kStatus) GdkToolRegistry_SetInvalid(GdkToolInfo info, GdkToolRegistryInvalidReason reason);
GdkFx(kStatus) GdkToolRegistry_RemoveFromValid(GdkToolInfo info);

GdkFx(kStatus) GdkToolRegistry_ConstructInfo(kType type, GdkToolInfo* info);

GdkFx(kBool) GdkToolRegistry_ValidateName(const kChar* name);
GdkFx(kBool) GdkToolRegistry_IsNameChar(kChar ch);

kEndHeader()

#endif
