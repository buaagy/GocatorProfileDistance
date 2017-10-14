/** 
 * @file    GdkLib.h
 * @brief   Gdk library management functions. 
 *
 * @internal
 * Copyright (C) 2015 by LMI Technologies Inc.  All rights reserved.
 */
#ifndef GDK_LIB_H
#define GDK_LIB_H

#include <kApi/kApiDef.h>
#include <kFireSync/kFsDef.h>
#include <Gdk/GdkDef.h>

kBeginHeader()

/**
* Constructs the Gocator Tools library.
*
* @public
* @ingroup  Gdk
* @param    assembly    Receives an assembly object representing the library.
* @return               Operation status.
*/
GdkFx(kStatus) GdkLib_Construct(kAssembly* assembly);

kEndHeader()

#include <Gdk/GdkLib.x.h>

#endif
