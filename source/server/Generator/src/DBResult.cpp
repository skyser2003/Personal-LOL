#include "stdafx.h"
#include "DBResult.h"

DBResult::DBResult(MYSQL_RES* ret) : ret(*ret), count(ret == nullptr ? 0 : mysql_num_rows(ret))
{
	
}

int DBResult::Count() const
{
	return count;
}