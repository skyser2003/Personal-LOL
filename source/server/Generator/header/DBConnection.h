#pragma once

#include <boost/format.hpp>
#include "mysql.h"

#include "DBReadResult.h"
#include "DBWriteResult.h"

struct DBInfo
{
	std::string host;
	std::string db;
	std::string user;
	std::string pw;
};

class DBConnection
{
public:
	DBConnection(const DBInfo& info);
	~DBConnection();

	bool Connect(int retryCount, int retrySleepMs = 5000);

	DBReadResult ReadQuery(const std::string& query);

	template <typename ...Args>
	auto ReadQuery(const std::string& query, Args... args)
	{
		auto format = (boost::format(query) % ... % Escape(args));

		return ReadQuery(format.str());
	}

	DBWriteResult WriteQuery(const std::string& query);

	template <typename ...Args>
	auto WriteQuery(const std::string& query, Args... args)
	{
		auto format = (boost::format(query) % ... % Escape(args));

		return WriteQuery(format.str());
	}

private:
	template <typename ArgType>
	std::string Escape(ArgType arg)
	{
		const auto strArg = std::to_string(arg);
		return Escape(strArg);
	}

	template <>
	std::string Escape(std::string arg)
	{
		auto* dest = new char[arg.length() * 2 + 1];

		mysql_real_escape_string(&conn, dest, arg.c_str(), arg.length());

		auto ret = std::string(dest);
		delete[] dest;

		return ret;
	}

	const DBInfo info;
	MYSQL& conn;
};