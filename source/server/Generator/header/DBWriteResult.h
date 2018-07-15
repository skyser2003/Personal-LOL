#pragma once

class DBWriteResult
{
public:
	DBWriteResult(MYSQL_RES* res, int affectedRowsCount);

	int AffectedRowsCount() const;

private:
	MYSQL_RES& res;

	const int affectedRowsCount;
};