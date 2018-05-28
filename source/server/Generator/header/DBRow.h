#pragma once

#include <map>
#include <string>

class DBRow
{
public:
	DBRow(MYSQL_ROW row, const std::map<std::string, int>& fieldIndexMap);

	const char* Get(const std::string& fieldName) const;

private:
	MYSQL_ROW row;
	const std::map<std::string, int>& fieldIndexMap;
};