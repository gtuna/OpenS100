// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
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