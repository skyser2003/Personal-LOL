#include "stdafx.h"
#include "DBRow.h"

DBRow::DBRow(MYSQL_ROW row, const std::map<std::string, int>& fieldIndexMap) : row(row), fieldIndexMap(fieldIndexMap)
{

}

const char* DBRow::Get(const std::string & fieldName) const
{
	auto it = fieldIndexMap.find(fieldName);

	if (it == fieldIndexMap.end())
	{
		return nullptr;
	}
	else
	{
		return row[it->second];
	}
}