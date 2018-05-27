#pragma once

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

private:
	const DBInfo info;
	MYSQL& conn;
};