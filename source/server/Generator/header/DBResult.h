#pragma once

class DBResult
{
public:
	DBResult(MYSQL_RES* ret);

	int Count() const;

private:
	MYSQL_RES& ret;
	const int count;
};