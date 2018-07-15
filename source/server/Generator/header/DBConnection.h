#pragma once

#include <boost/format.hpp>

#include "DBResult.h"

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
	DBResult Query(const std::string& query);

	template <typename ...Args>
	DBResult Query(const std::string& query, Args... args)
	{
		auto format = (boost::format(query) % ... % args);

		return Query(format.str());
	}

private:
	const DBInfo info;
	MYSQL& conn;
};