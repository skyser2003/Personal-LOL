#include "stdafx.h"
#include "DBReadResult.h"

DBReadResult::DBReadResult(MYSQL_RES* res) : res(*res), count(res == nullptr ? 0 : mysql_num_rows(res))
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

int DBReadResult::Count() const
{
	return count;
}

DBRow DBReadResult::Next()
{
	auto row = mysql_fetch_row(&res);

	return DBRow{ row, fieldIndexMap };
}