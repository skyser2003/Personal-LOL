#pragma once

#include <map>

#include "DBRow.h"

class DBResult
{
public:
	DBResult(MYSQL_RES* res);

	int Count() const;
	DBRow Next();

private:
	MYSQL_RES & res;

	const int count;
	std::map<std::string, int> fieldIndexMap;
};