#include "stdafx.h"
#include "F_C2FT.h"
#include "ISO8211Fuc.h"
#include "NonPrintableCharacter.h"

F_C2FT::F_C2FT()
{

}

F_C2FT::~F_C2FT()
{

}

int F_C2FT::GetSize()
{
	return 16;
}

void F_C2FT::ReadField(BYTE *&buf)
{
	m_ycoo = buf2double(buf, 8);
	m_xcoo = buf2double(buf, 8);
}

BOOL F_C2FT::Save(CFile *file)
{
	file->Write(&m_ycoo, 8);
	file->Write(&m_xcoo, 8);
	file->Write(&NonPrintableCharacter::fieldTerminator, 1);

	return TRUE;
}

int  F_C2FT::GetFieldLength()
{
	unsigned len = 0;
	len += F_C2FT::GetSize();
	return ++len;
}