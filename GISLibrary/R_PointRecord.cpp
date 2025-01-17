#include "StdAfx.h"
#include "R_PointRecord.h"
#include "DRDirectoryInfo.h"
#include "F_C2IT.h"
#include "F_C3IT.h"
#include "F_INAS.h"

R_PointRecord::R_PointRecord(void)
{
	m_prid.m_name.RCNM = 110;
}

R_PointRecord::~R_PointRecord(void)
{
	delete m_c2it;
	delete m_c3it;
	for (auto itor = m_inas.begin(); itor != m_inas.end(); itor++)
	{
		delete *itor;
	}
}

BOOL R_PointRecord::ReadRecord(DRDirectoryInfo *dir, BYTE*& buf)
{	
	USES_CONVERSION;
	int i = 0, j = 0;
	for(i = 0; i < dir->m_count; i++)
	{
		if(dir->GetDirectory(i)->tag == *((unsigned int*)"PRID"))
		{
			m_prid.ReadField(buf);
		}
		else if(dir->GetDirectory(i)->tag == *((unsigned int*)"INAS"))
		{
			F_INAS *inas = new F_INAS();
			inas->ReadField(buf);
			m_inas.push_back(inas);

			OutputDebugString(L"@@@ INAS @@@ \n\n");
		}
		else if (dir->GetDirectory(i)->tag == *((unsigned int*)"C2IT"))
		{
			m_c2it = new F_C2IT();
			m_c2it->ReadField(buf);
		}
		else if (dir->GetDirectory(i)->tag == *((unsigned int*)"C3IT"))
		{
			m_c3it = new F_C3IT();
			m_c3it->ReadField(buf);
		}
		else if (dir->GetDirectory(i)->tag == *((unsigned int*)"C2FT"))
		{
		}
		else if (dir->GetDirectory(i)->tag == *((unsigned int*)"C3FT"))
		{
		}
		else
		{
			buf += dir->GetDirectory(i)->length;
		}
		
		if(*(buf++)!= 0x1E)//{}
			TRACE(W2A(TEXT("terminator error")));
	}

	return TRUE;
}

int R_PointRecord::GetRCID()
{
	return  m_prid.m_name.RCID;
}

std::wstring R_PointRecord::GetRCIDasWstring() 
{
	return std::to_wstring(GetRCID());
}

void R_PointRecord::SetC2IT(F_C2IT* value)
{
	m_c2it = value;
}

void R_PointRecord::SetC3IT(F_C3IT* value) 
{
	m_c3it = value;
}