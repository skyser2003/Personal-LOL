#pragma once

#include "DBRow.h"

class DBResult
{
public:
	DBResult(MYSQL_RES* ret);

	int Count() const;
	DBRow Next();

private:
	MYSQL_RES& ret;
	const int count;
};