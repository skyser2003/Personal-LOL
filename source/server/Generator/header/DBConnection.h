#pragma once

#include "DBResult.h"

class DBConnection
{
public:
	struct DBInfo
	{
		std::string host;
		std::string db;
		std::string user;
		std::string pw;
	};

	DBConnection(const DBInfo& info);
	~DBConnection();

	bool Connect();
	DBResult Query(const std::string& query);

private:
	const DBInfo info;
	MYSQL& conn;
};