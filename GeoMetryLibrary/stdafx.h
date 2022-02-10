// stdafx.h : An include file that contains standard system
// include files and project-specific include files 
// that are used frequently but not frequently changed.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely used content from Windows headers.
#endif

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 common controls.
#endif

#include <map>
#include <gdiPlus.h>
#pragma comment(lib, "gdiplus")
using namespace Gdiplus;

#include "..\\extlibs\\Clipper\\include\\clipper.hpp"

#ifndef _TEXTWHITEBACK	
	//#define _TEXTWHITEBACK	
#endif

#import <msxml4.dll>
#include "msxml.h"