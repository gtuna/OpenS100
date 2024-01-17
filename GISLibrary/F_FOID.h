#pragma once
#include "Field.h"

class F_FOID : public Field
{
public:
	F_FOID();
	F_FOID(const F_FOID& other);
	F_FOID(int AGEN, int FIDN, int FIDS);
	virtual ~F_FOID();

public:
	// Producing Agency
	// b12
	// Agency code	
	int AGEN = 0;

	// Feature Identification Number
	// b14
	// Range : 1 to 2^32 - 2
	int FIDN = 0;
		
	// Feature Identification Subdivision
	// b12
	// Range : 1 to 2^32 - 2
	int FIDS = 0;

public:
	virtual F_FOID operator=(const F_FOID& other);

public:
	void ReadField(BYTE *&buf);
	bool WriteField(CFile* file);

	int GetFieldLength();

	__int64 GetName();
};