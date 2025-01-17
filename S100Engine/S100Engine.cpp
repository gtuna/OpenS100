#include "stdafx.h"
#include "S100Engine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CS100EngineApp

BEGIN_MESSAGE_MAP(CS100EngineApp, CWinApp)
END_MESSAGE_MAP()

CS100EngineApp::CS100EngineApp()
{
	
}


const GUID CDECL _tlid = {0x94dfd6cf,0xdd49,0x422c,{0xb3,0x05,0x6d,0x33,0x3d,0x35,0x50,0xd3}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



BOOL CS100EngineApp::InitInstance()
{
	CWinApp::InitInstance();

	COleObjectFactory::RegisterAll();

	return TRUE;
}


STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}



STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}



STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}



STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}


S100Engine::S100Engine()
{
}


S100Engine::~S100Engine()
{
}


void S100Engine::CreateBackgroundGeometry(ID2D1Factory1* pD2Factory)
{
	s100Render.CreateBackgroundGeometry(pD2Factory);
}


bool S100Engine::OpenS101(CString _path)
{
	return s100DatasetManager.OpenS101(_path);
}

void S100Engine::CreateBitmapImage(ID2D1Factory1* pDirect2dFactory, IWICImagingFactory* pImagingFactory, ID2D1StrokeStyle1* pStrokeStyleS101Solid)
{
	s100PCManager.CreateBitmapImage(pDirect2dFactory, pImagingFactory, pStrokeStyleS101Solid);
}


void S100Engine::CreateLineImage(ID2D1Factory1* pDirect2dFactory, IWICImagingFactory* pImagingFactory, ID2D1StrokeStyle1* pStrokeStyleS101Solid)
{
	s100PCManager.CreateLineImage(pDirect2dFactory, pImagingFactory, pStrokeStyleS101Solid);
}


bool S100Engine::OpenS101SENC(CString path)
{
	return s100DatasetManager.OpenS101SENC(path);
}


void S100Engine::Draw(ID2D1Factory1* pDirect2dFactory, ID2D1DCRenderTarget* pRenderTarget, IDWriteTextFormat* pTextFormat, ID2D1SolidColorBrush* pBrush, ID2D1StrokeStyle1* pStrokeStyleS101Solid, ID2D1StrokeStyle1* pStrokeStyleS101Dash, CRect& rectView)
{
	s100Render.Draw(s100DatasetManager, s100PCManager, pDirect2dFactory, pRenderTarget, pTextFormat, pBrush, pStrokeStyleS101Solid, pStrokeStyleS101Dash, s100PCManager.areaFillInfo, rectView);
}


void S100Engine::DrawSymbol(
	std::wstring _symbolName,
	ID2D1RenderTarget* pRenderTarget,
	ID2D1SolidColorBrush* pBrush,
	ID2D1StrokeStyle1* pStrokeStyle,
	D2D1_POINT_2F point,
	FLOAT rotation,
	FLOAT scale)
{
	s100PCManager.Draw(
		_symbolName,
		pRenderTarget,
		pBrush,
		pStrokeStyle,
		point,
		rotation,
		scale);
}


bool S100Engine::OpenS100PortrayalCatalogue(CString folderPath)
{
	return true;
}


bool S100Engine::OpenS100ColorProfile(std::wstring _path)
{
	return s100PCManager.OpenS100ColorProfile(_path);
}


bool S100Engine::OpenS100Symbol(std::wstring _path)
{
	return s100PCManager.OpenS100Symbol(_path);
}


bool S100Engine::OpenS100AreaFills(std::wstring _path)
{
	return s100PCManager.OpenS100AreaFills(_path);
}


bool S100Engine::OpenS100LineStyles(std::wstring _path)
{
	return s100PCManager.OpenS100LineStyles(_path);
}


void S100Engine::CreateSVGGeometry(ID2D1Factory1* pDirect2dFactory)
{
	s100PCManager.CreateSVGGeometry(pDirect2dFactory);
}


void S100Engine::CreateS100DrawingUnit(ID2D1Factory1* pDirect2dFactory)
{
	s100DatasetManager.CreateS100DrawingUnit(pDirect2dFactory, s100PCManager);
}


void S100Engine::CreateBitmapBrush(ID2D1RenderTarget* pRenderTarget)
{
	s100PCManager.CreateBitmapBrush(pRenderTarget);
}


void S100Engine::DeleteBitmapBrush()
{
	s100PCManager.DeleteBitmapBrush();
}


void S100Engine::DeleteBitmapImage()
{
	s100PCManager.DeleteBitmapImage();
}


void S100Engine::DeleteS100DrawingUnit()
{
	s100DatasetManager.DeleteS100DrawingUnit();
}


void S100Engine::KeyDown(UINT nChar, CRect& rectView, int dpiX, int dpiY)
{
	s100DatasetManager.GetBoundingBox(s100Render.xmin, s100Render.ymin, s100Render.xmax, s100Render.ymax);

	s100Render.KeyDown(nChar, rectView, dpiX, dpiY);
}


void S100Engine::SetD2Factory(ID2D1Factory1* factory)
{
	pDirect2dFactory = factory;
}