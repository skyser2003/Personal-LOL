#include "stdafx.h"
#include "DataSaver.h"

#include "DBConnection.h"

DataSaver::DataSaver(const std::shared_ptr<DBConnection>& conn) : conn(conn)
{
}

bool DataSaver::RegisterUser(const std::string& summonerName)
{
	const auto result = conn->WriteQuery("INSERT INTO `user` (`summoner_name`) VALUES (%s)", summonerName);

	return result.AffectedRowsCount() != 0;
}