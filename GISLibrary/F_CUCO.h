#pragma once
#include "Field.h"

struct CUCO;
class F_CUCO : public Field
{
public:
	F_CUCO();
	virtual ~F_CUCO();
	
public:
	std::list<CUCO*> m_arr;

public:
	void ReadField(BYTE *&buf);
	void ReadField(BYTE *&buf, int loopCnt);
	bool WriteField(CFile* file);

	int GetFieldLength();

	void Insert(RecordName name, int ornt);
	void Insert(int rcnm, int rcid, int ornt);
	void Insert(GISLibrary::RCNM rcnm, int rcid, int ornt);
};