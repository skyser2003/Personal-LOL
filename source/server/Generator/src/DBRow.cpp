#include "stdafx.h"
#include "DBRow.h"

DBRow::DBRow(MYSQL_ROW row, const std::map<std::string, int>& fieldIndexMap) : row(row), fieldIndexMap(fieldIndexMap)
{

}

const char* DBRow::GetRaw(const std::string & fieldName) const
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

template <>
int DBRow::Get(const std::string& fieldName) const
{
	const auto* raw = GetRaw(fieldName);

	if (raw == nullptr)
	{
		return 0;
	}

	return std::stoi(raw);
}

template <>
std::string DBRow::Get(const std::string& fieldName) const
{
	const auto* raw = GetRaw(fieldName);

	if (raw == nullptr)
	{
		return "";
	}

	return raw;
}