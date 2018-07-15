#pragma once

#include <boost/format.hpp>

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
		auto format = (boost::format(query) % ... % args);

		return ReadQuery(format.str());
	}

	DBWriteResult WriteQuery(const std::string& query);

	template <typename ...Args>
	auto WriteQuery(const std::string& query, Args... args)
	{
		auto format = (boost::format(query) % ... % args);

		return WriteQuery(format.str());
	}

private:
	const DBInfo info;
	MYSQL& conn;
};