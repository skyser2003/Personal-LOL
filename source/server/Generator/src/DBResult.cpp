#include "stdafx.h"
#include "DBResult.h"

DBResult::DBResult(MYSQL_RES* res) : res(*res), count(res == nullptr ? 0 : mysql_num_rows(res))
{
	if (res == nullptr)
	{
		return;
	}

	for (auto i = 0; auto* field = mysql_fetch_field(res); ++i)
	{
		fieldIndexMap[field->name] = i;
	}
}

int DBResult::Count() const
{
	return count;
}

DBRow DBResult::Next()
{
	auto row = mysql_fetch_row(&res);

	return DBRow{ row, fieldIndexMap };
}