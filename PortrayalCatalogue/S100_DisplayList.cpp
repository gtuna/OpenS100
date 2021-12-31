#include "stdafx.h"

#include "S100_DisplayList.h"
#include "S100_NullInstruction.h"
#include "S100_PointInstruction.h"
#include "S100_LineInstruction.h"
#include "S100_AreaInstruction.h"
#include "S100_TextInstruction.h"
#include "S100_AugmentedRay.h"
#include "S100_AugmentedPath.h"

S100_DisplayList::S100_DisplayList()
{
	displayInstructions.clear();
}

S100_DisplayList::~S100_DisplayList()
{
	RemoveInstructions();
}

void S100_DisplayList::GetContents(MSXML2::IXMLDOMNodePtr pNode)
{
	if (!pNode)
		return;

	std::wstring nodeName = (LPCTSTR)pNode->GetnodeName();
	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	
	int cnt = pNodeList->Getlength();
	for (int i = 0; i < pNodeList->Getlength(); i++)
	{
		MSXML2::IXMLDOMNodePtr pNode = pNodeList->Getitem(i);

		if (!pNode)
			continue;

		std::wstring nodeName = (LPCTSTR)pNode->GetnodeName();

		if (nodeName.compare(L"nullInstruction") == 0)
		{
			S100_NullInstruction *in = new S100_NullInstruction();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"pointInstruction") == 0)
		{
			S100_PointInstruction *in = new S100_PointInstruction();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"lineInstruction") == 0)
		{
			S100_LineInstruction *in = new S100_LineInstruction();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"areaInstruction") == 0)
		{
			S100_AreaInstruction *in = new S100_AreaInstruction();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"coverageInstruction") == 0)
		{
		}
		else if (nodeName.compare(L"textInstruction") == 0)
		{
			S100_TextInstruction *in = new S100_TextInstruction();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"augmentedPoint") == 0)
		{
		}
		else if (nodeName.compare(L"augmentedRay") == 0)
		{
			S100_AugmentedRay *in = new S100_AugmentedRay();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"augmentedPath") == 0)
		{
			S100_AugmentedPath *in = new S100_AugmentedPath();
			in->GetContents(pNode);
			displayInstructions.push_back((S100_Instruction*)in);
		}
		else if (nodeName.compare(L"augmentedArea") == 0)
		{
		}
	}
}

void S100_DisplayList::GetContents(pugi::xml_node node)
{
	auto nodeName = node.name();

	if (nodeName == "nullInstruction")
	{
		S100_NullInstruction *in = new S100_NullInstruction();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
	else if (nodeName == "pointInstruction")
	{
		S100_PointInstruction *in = new S100_PointInstruction();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
	else if (nodeName == "lineInstruction")
	{
		S100_LineInstruction *in = new S100_LineInstruction();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
	else if (nodeName == "areaInstruction")
	{
		S100_AreaInstruction *in = new S100_AreaInstruction();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
	else if (nodeName == "textInstruction")
	{
		S100_TextInstruction *in = new S100_TextInstruction();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
	else if (nodeName == "augmentedPoint")
	{
	}
	else if (nodeName == "augmentedRay")
	{
		S100_AugmentedRay *in = new S100_AugmentedRay();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
	else if (nodeName == "augmentedPath")
	{
		S100_AugmentedPath *in = new S100_AugmentedPath();
		in->GetContents(node);
		displayInstructions.push_back((S100_Instruction*)in);
	}
}

void S100_DisplayList::RemoveInstructions()
{
	for (auto itor = displayInstructions.begin(); itor != displayInstructions.end(); itor++)
	{
		S100_Instruction* it = *itor;

		/*
		*  Type Of Instruction
		*  0 : Null Instruction
		*  1 : Point Instruction
		*  2 : Line Instruction
		*  3 : Area Instruction
		** 4 : Coverage Instruction
		*  5 : Text Instruction
		** 6 : Augmented Point
		** 7 : Augmented Ray
		** 8 : Augmented Path
		** 9 : Augmented Area
		*/
		switch (it->GetType())
		{
		case 0:
			delete(S100_NullInstruction*)it;
			break;
		case 1:
			delete(S100_PointInstruction*)it;
			break;
		case 2:
			delete(S100_LineInstruction*)it;
			break;
		case 3:
			delete(S100_AreaInstruction*)it;
			break;
		case 4:
			break;
		case 5:
			delete(S100_TextInstruction*)it;
			break;
		case 6:
			break;
		case 7:
			delete(S100_AugmentedRay*)it;
			break;
		case 8:
			delete(S100_AugmentedPath*)it;
			break;
		case 9:
			break;
		}
	}

	displayInstructions.clear();
}

void S100_DisplayList::SetDisplayInstruction(S100_Instruction* value)
{
	displayInstructions.push_back(value);
}
void S100_DisplayList::SetDisplayInstructions(std::list<S100_Instruction*> value) {
	displayInstructions = value;
}

S100_Instruction* S100_DisplayList::GetDisplayInstruction(int index) {
	auto it = displayInstructions.begin();
	advance(it, index);
	return *it;
}
std::list<S100_Instruction*> S100_DisplayList::GetDisplayInstructions()
{
	return displayInstructions;
}
std::list<S100_Instruction*> S100_DisplayList::GetAlertInstructions()
{
	return alertInstructions;
}

void S100_DisplayList::AddAlertInstruction(S100_Instruction* _ins)
{
	alertInstructions.push_back(_ins);
}