#pragma once

#include <memory>

class DBConnection;

class DataSaver
{
public:
	DataSaver(const std::shared_ptr<DBConnection>& conn);

	void RegisterUser(const std::string& summonerName);

private:
	std::shared_ptr<DBConnection> conn;
};