#include "stdafx.h"
#include "S100_AreaFillFile.h"
#include <string>

S100_AreaFillFile::S100_AreaFillFile()
{

}

S100_AreaFillFile::~S100_AreaFillFile()
{

}

void S100_AreaFillFile::Setid(std::wstring& value)
{
	id = value;
}

std::wstring S100_AreaFillFile::Getid()
{
	return id;
}

void S100_AreaFillFile::SetDescription(S100_Description* value) 
{
	description = *value;
}

S100_Description* S100_AreaFillFile::GetDescription() 
{
	return &description;
}

void S100_AreaFillFile::SetFileName(std::wstring& value) 
{
	fileName = value;
}

std::wstring S100_AreaFillFile::GetFileName() 
{
	return fileName;
}

void S100_AreaFillFile::SetFileType(std::wstring& value)
{
	fileType = value;
}

std::wstring S100_AreaFillFile::GetFileType()
{
	return fileType;
}

void S100_AreaFillFile::SetFileFormat(std::wstring& value)
{
	fileFormat = value;
}

std::wstring S100_AreaFillFile::GetFileFormat()
{
	return fileFormat; 
}


void S100_AreaFillFile::GetContents(MSXML2::IXMLDOMNodePtr pNode)
{
	if (!pNode)
		return;

	MSXML2::IXMLDOMNamedNodeMapPtr pAttr = pNode->Getattributes();
	MSXML2::IXMLDOMNodePtr pAttrNP;
	pAttrNP = pAttr->getNamedItem(L"id");
	VARIANT value;
	pAttrNP->get_nodeValue(&value);

	id = std::wstring(value.bstrVal).c_str();

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();

	for (int i = 0; i < pNodeList->Getlength(); i++)
	{
		MSXML2::IXMLDOMNodePtr pNode = pNodeList->Getitem(i);

		if (!pNode)
			continue;

		std::wstring nodeName = (LPCTSTR)pNode->GetnodeName();

		if (nodeName.compare(L"description") == 0)
		{
			description.GetContents(pNode->childNodes);
		}
		else if (nodeName.compare(L"fileName") == 0)
		{
			fileName = std::wstring(pNode->Gettext());
		}
		else if (nodeName.compare(L"fileType") == 0)
		{
			fileType = std::wstring(pNode->Gettext());
		}
		else if (nodeName.compare(L"fileFormat") == 0)
		{
			fileFormat = std::wstring(pNode->Gettext());
		}
	}
}

void S100_AreaFillFile::GetContents(pugi::xml_node& node)
{
	if (!node)
	{
		return;
	}

	auto idvalue = node.attribute("id").value(); //Bring the attribute value.
	if (idvalue)
	{
		id = pugi::as_wide(idvalue);
	}

	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();

		if (!strcmp(instructionName, "description"))
		{
			description.GetContents(instruction);
		}

		else if (!strcmp(instructionName, "fileName"))
		{
			fileName = pugi::as_wide(instruction.child_value());
		}

		else if (!strcmp(instructionName, "fileType"))
		{
			fileType = pugi::as_wide(instruction.child_value());
		}

		else if (!strcmp(instructionName, "fileFormat"))
		{
			fileFormat = pugi::as_wide(instruction.child_value());
		}
	}
}