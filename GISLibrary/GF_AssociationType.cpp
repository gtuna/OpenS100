#include "stdafx.h"
#include "GF_AssociationType.h"

namespace GF
{
	AssociationType::AssociationType()
	{

	}

	AssociationType::~AssociationType()
	{

	}

	std::string AssociationType::GetRole()
	{
		return role.GetCode();
	}

	void AssociationType::SetRole(std::string code)
	{
		role.SetCode(code);
	}

}