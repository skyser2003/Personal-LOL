#pragma once

#include <map>
#include <string>

class DBRow
{
public:
	DBRow(MYSQL_ROW row, const std::map<std::string, int>& fieldIndexMap);

	template <typename T>
	T Get(const std::string& fieldName) const;

private:
	const char* GetRaw(const std::string& fieldName) const;

	MYSQL_ROW row;
	const std::map<std::string, int>& fieldIndexMap;
};