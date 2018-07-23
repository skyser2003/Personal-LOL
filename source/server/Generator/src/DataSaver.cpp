#include "stdafx.h"
#include "DataSaver.h"

#include "DBConnection.h"

DataSaver::DataSaver(const std::shared_ptr<DBConnection>& conn) : conn(conn)
{
}

bool DataSaver::RegisterUser(long accountId, long summonerId, const std::string& summonerName)
{
	const auto result = conn->WriteQuery("INSERT INTO `user` (`account_id`, `summoner_id`, `summoner_name`) VALUES (%ld, %ld, '%s')", accountId, summonerId, summonerName);

	return result.AffectedRowsCount() != 0;
}