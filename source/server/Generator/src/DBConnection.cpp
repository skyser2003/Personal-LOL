#include "stdafx.h"
#include "DBConnection.h"

DBConnection::DBConnection(const DBInfo& info) : info(info), conn(*mysql_init(nullptr))
{
}

DBConnection::~DBConnection()
{
	mysql_close(&conn);
}

std::string DBConnection::ConcatQueryArgs(const std::string& arg1, const std::string& arg2)
{
	return arg1 + ", " + arg2;
}

bool DBConnection::Connect(int retryCount, int retrySleepMs)
{
	const auto tryConnect = [this]()
	{
		return mysql_real_connect(&conn, info.host.c_str(), info.user.c_str(), info.pw.c_str(), info.db.c_str(), 3306, nullptr, 0);;
	};

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

DBReadResult DBConnection::ReadQuery(const std::string& query)
{
	if (mysql_real_query(&conn, query.c_str(), query.size()) != 0)
	{
		// TODO: some error logging
		return DBReadResult(nullptr);
	}
	else
	{
		auto* result = mysql_store_result(&conn);

		return DBReadResult(result);
	}
}

DBWriteResult DBConnection::WriteQuery(const std::string& query)
{
	if (mysql_real_query(&conn, query.c_str(), query.size()) != 0)
	{
		// TODO: some error logging
		return DBWriteResult(nullptr, 0);
	}
	else
	{
		auto* result = mysql_store_result(&conn);
		auto affectedRowsCount = mysql_affected_rows(&conn);

		return DBWriteResult(result, affectedRowsCount);
	}
}


std::string DBConnection::Escape(const char* arg) const
{
	return Escape(std::string(arg));
}

std::string DBConnection::Escape(const std::string& arg) const
{
	auto dest = std::make_unique<char[]>(arg.length() * 2 + 1);

	mysql_real_escape_string(&conn, dest.get(), arg.c_str(), arg.length());

	return dest.get();
}

std::string DBConnection::EscapeTupleElem(const char* arg) const
{
	return EscapeTupleElem(std::string(arg));
}
std::string DBConnection::EscapeTupleElem(const std::string& arg) const
{
	return "'" + Escape(arg) + "'";
}