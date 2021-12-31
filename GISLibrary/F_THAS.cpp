#include "StdAfx.h"
#include "F_THAS.h"
#include "THAS.h"
#include "ISO8211Fuc.h"
#include "NonPrintableCharacter.h"

F_THAS::F_THAS(void)
{

}

F_THAS::~F_THAS(void)
{
	POSITION pos = m_arr.GetHeadPosition();
	while(pos!=NULL)
	{
		THAS *thas = m_arr.GetNext(pos);
		delete thas;
	}
}

void F_THAS::ReadField(BYTE *&buf)
{
	while(*buf != 0x1E)
	{
		THAS *thas = new THAS();
		thas->m_name.RCNM = *(buf++);
		thas->m_name.RCID = buf2uint(buf, 4);
		thas->m_taui = *(buf++);
	}
}

void F_THAS::ReadField(BYTE *&buf, int loopCnt)
{
	for(int i = 0; i < loopCnt; i++)
	{
		THAS *thas = new THAS();
		thas->m_name.RCNM = *(buf++);
		thas->m_name.RCID = buf2uint(buf, 4);
		thas->m_taui = *(buf++);
	}
}

BOOL F_THAS::Save(CFile *file)
{
	POSITION pos = m_arr.GetHeadPosition();

	while(pos != NULL)
	{
		THAS *thas = m_arr.GetNext(pos);
		
		file->Write(&thas->m_name.RCNM, 1);
		file->Write(&thas->m_name.RCID, 4);
		file->Write(&thas->m_taui, 1);
	}
	file->Write(&NonPrintableCharacter::fieldTerminator, 1);
	return TRUE;
}

int F_THAS::GetFieldLength()
{
	int len = 0;

	POSITION pos = m_arr.GetHeadPosition();
	while(pos!=NULL)
	{
		THAS *thas = m_arr.GetNext(pos);
		len += THAS::GetSize();
	}
	return ++len;
}