#pragma once

#include <memory>

class DBConnection;

class DataSaver
{
public:
	DataSaver(const std::shared_ptr<DBConnection>& conn);

	bool RegisterUser(const std::string& region, long accountId, long summonerId, const std::string& summonerName);

private:
	std::shared_ptr<DBConnection> conn;
};