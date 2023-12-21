#include "stdafx.h"
#include "SMultiPoint.h"

#include "../GeoMetryLibrary/Enum_WKBGeometryType.h"
#include "../GeoMetryLibrary/GeoCommonFuc.h"

#include <stdexcept>

SMultiPoint::SMultiPoint()
{
	
}

SMultiPoint::~SMultiPoint()
{
}

SGeometryType SMultiPoint::GetType()
{
	return SGeometryType::MultiPoint;
}

int SMultiPoint::GetNumPoints()
{
	return (int)m_pPoints.size();
}

double SMultiPoint::GetX(int index)
{
	try
	{
		return m_pPoints.at(index).x;
	}
	catch (std::out_of_range)
	{
		return 0;
	}
	return 0;
}

double SMultiPoint::GetY(int index)
{
	try
	{
		return m_pPoints.at(index).y;
	}
	catch (std::out_of_range)
	{
		return 0;
	}

	return 0;
}

double SMultiPoint::GetZ(int index)
{
	try
	{
		return m_pPoints.at(index).z;
	}
	catch (std::out_of_range)
	{
		return 0;
	}

	return 0;
}

void SMultiPoint::SetSize(int size)
{
	m_pPoints.resize(size);
}

void SMultiPoint::SetMBR()
{
	m_mbr.InitMBR();

	for (auto i = m_pPoints.begin(); i != m_pPoints.end(); i++)
	{
		m_mbr.CalcMBR(i->GetX(), i->GetY());
	}
}

void SMultiPoint::Add(double x, double y, double z)
{
	m_pPoints.push_back(GeoPointZ(x, y, z));
}

void SMultiPoint::Set(int index, double x, double y, double z)
{
	try
	{
		return m_pPoints.at(index).SetPoint(x, y, z);
	}
	catch (std::out_of_range)
	{
		return;
	}
}

bool SMultiPoint::ImportFromWkb(unsigned char* value, int size)
{
	if (value == nullptr ||
		value[0] != 0x01)
	{
		return false;
	}

	int type = 0;

	memcpy_s(&type, 4, value + 1, 4);

	if (type == (int)WKBGeometryType::wkbMultiPointZ)
	{
		int numPoints = 0;
		memcpy_s(&numPoints, 4, value + 5, 4);

		m_pPoints.resize(numPoints);

		for (int i = 0; i < numPoints; i++) {
			m_pPoints.at(i).ImportFromWkb(value + (9 + (29 * i)), 29);
		}
	}
	else if (type == (int)WKBGeometryType::wkbMultiPoint)
	{
		int numPoints = 0;
		memcpy_s(&numPoints, 4, value + 5, 4);
		
		m_pPoints.resize(numPoints);

		for (int i = 0; i < numPoints; i++) {
			m_pPoints.at(i).ImportFromWkb(value + (9 + (21 * i)), 21);
		}
	}
	else
	{
		return false;
	}

	SetMBR();

	return true;
}

bool SMultiPoint::ExportToWkb(unsigned char** value, int* size)
{
	int numPoints = GetNumPoints();
	*size = 9 + ((29) * numPoints);
	if (*value == nullptr)
	{
		*value = new unsigned char[*size];
	}
	memset(*value, 0, *size);

	(*value)[0] = 0x01;

	int type = (int)WKBGeometryType::wkbMultiPointZ;

	memcpy_s((*value) + 1, 4, &type, 4);

	memcpy_s((*value) + 5, 4, &numPoints, 4);

	for (int i = 0; i < numPoints; i++)
	{
		int locSize = 0;
		auto mem = (*value) + (9 + (29 * i));

		GeoPointZ localPoint = m_pPoints.at(i);
		inverseProjection(localPoint.x, localPoint.y);
		localPoint.ExportToWkb(&mem, &locSize);
	}

	return true;
}

SMultiPoint* SMultiPoint::Clone() const
{
	SMultiPoint* mpt = new SMultiPoint();

	//Geometry
	mpt->id = id;

	mpt->m_mbr.xmin = m_mbr.xmin;
	mpt->m_mbr.ymin = m_mbr.ymin;
	mpt->m_mbr.xmax = m_mbr.xmax;
	mpt->m_mbr.ymax = m_mbr.xmax;

	//SGeometry
	if (sizeOfPoint > 0)
	{
		if (mpt->viewPoints)
		{
			delete[] mpt->viewPoints;
			mpt->viewPoints = nullptr;
		}

		mpt->sizeOfPoint = sizeOfPoint;
		mpt->viewPoints = new POINT[sizeOfPoint];
		memset(mpt->viewPoints, 0x00, sizeof(POINT) * sizeOfPoint);
		memcpy(mpt->viewPoints, viewPoints, sizeof(POINT) * sizeOfPoint);
	}

	//SMultiPoint
	for (const auto& iter : m_pPoints)
	{
		GeoPointZ pt;
		pt.x = iter.x;
		pt.y = iter.y;
		pt.z = iter.z;
		mpt->m_pPoints.push_back(pt);
	}

	return mpt;
}

