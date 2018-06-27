#include "stdafx.h"
#include "DBConnection.h"

DBConnection::DBConnection(const DBInfo& info) : info(info), conn(*mysql_init(nullptr))
{
}

DBConnection::~DBConnection()
{
	mysql_close(&conn);
}

bool DBConnection::Connect(int retryCount, int retrySleepMs)
{
	const auto tryConnect = [this]()
	{
		return mysql_real_connect(&conn, info.host.c_str(), info.user.c_str(), info.pw.c_str(), info.db.c_str(), 3306, nullptr, 0);;
	};

	// TODO
	/*
	const auto retryCondition = retryCount < 0 ? []() -> bool { return true; }
		: [&retryCount]()
	{
		return (retryCount--) == 0;
	};
	*/

	const auto test = [&retryCount]()
	{
		return (retryCount--) == 0;
	};

	const auto test2 = []() {	return true; };

	if (tryConnect() != nullptr)
	{
		return true;
	}
	else if (retryCount < 0)
	{
		while (true)
		{
			if (tryConnect() == nullptr)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(retrySleepMs));
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		while (retryCount--)
		{
			if (tryConnect() == nullptr)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(retrySleepMs));
			}
			else
			{
				break;
			}
		}
	}
}

DBResult DBConnection::Query(const std::string& query)
{
	if (mysql_real_query(&conn, query.c_str(), query.size()) != 0)
	{
		// TODO: some error logging
		return DBResult(nullptr);
	}
	else
	{
		auto* result = mysql_store_result(&conn);

		return DBResult(result);
	}
}