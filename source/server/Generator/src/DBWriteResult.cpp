#include "stdafx.h"
#include "DBWriteResult.h"

DBWriteResult::DBWriteResult(MYSQL_RES* res, int affectedRowsCount) : res(*res), affectedRowsCount(affectedRowsCount)
{
}

int DBWriteResult::AffectedRowsCount() const
{
	return affectedRowsCount;
}