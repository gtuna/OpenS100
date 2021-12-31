// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE 클래스입니다.
#include <afxodlgs.h>       // MFC OLE 대화 상자 클래스입니다.
#include <afxdisp.h>        // MFC 자동화 클래스입니다.
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC 데이터베이스 클래스입니다.
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO 데이터베이스 클래스입니다.
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#import "msxml4.dll"
#include "msxml.h"
#include <msxml.h>

#include <d2d1.h>
#include <d2d1_1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")

#define FACTOR 0.1f
#define PIXEL_MM 0.161f
#define WIDTH_MM 360.0 * FACTOR * PIXEL_MM
#define EARTH_2PIR 40075000000.0f
#define SCALE_OFFSET 10

#define IsCTRLPressed()  ( 0x8000 ==(GetKeyState(VK_CONTROL) & 0x8000 ))

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define LAT_LIMIT 85.0f
float ProjectionX(float lon);
float ProjectionY(float lat);
D2D1_POINT_2F Projection(D2D1_POINT_2F point);
D2D1_POINT_2F ProjectionAndApplyFactor(D2D1_POINT_2F point);
float InverseProjectionX(float lon);
float InverseProjectionY(float lat);
D2D1_POINT_2F InverseProjection(D2D1_POINT_2F point);

#include "../LibMFCUtil/LibMFCUtil.h"

#define OUTPUT_DEBUG_STRING 1

#ifndef D2_SAFE_RELEASE
#define D2_SAFE_RELEASE

template<class Interface>
inline void SafeRelease(Interface **ppInterfaceToRelease)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

#endif