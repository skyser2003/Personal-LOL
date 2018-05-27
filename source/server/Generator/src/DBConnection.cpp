#include "stdafx.h"
#include "DBConnection.h"

DBConnection::DBConnection(const DBInfo& info) : info(info), conn(*mysql_init(nullptr))
{
}

DBConnection::~DBConnection()
{
	mysql_close(&conn);
}

bool DBConnection::Connect()
{
	const auto result = mysql_real_connect(&conn, info.host.c_str(), info.user.c_str(), info.pw.c_str(), info.db.c_str(), 3306, nullptr, 0);

	if (result == nullptr)
	{
		// TODO: some error logging

		return false;
	}
	else
	{
		return true;
	}
}

DBResult DBConnection::Query(const std::string& query)
{
	if (mysql_real_query(&conn, query.c_str(), query.size()) != 0)
	{
		// TODO: some error logging
		auto* result = mysql_store_result(&conn);

		return DBResult(result);
	}
	else
	{
		return DBResult(nullptr);
	}
}