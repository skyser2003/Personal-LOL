#include "stdafx.h"
#include "DataSaver.h"

#include "DBConnection.h"

DataSaver::DataSaver(const std::shared_ptr<DBConnection>& conn) : conn(conn)
{
}

bool DataSaver::RegisterUser(const std::string& region, long accountId, long summonerId, const std::string& summonerName)
{
	const auto result = conn->WriteQuery("INSERT INTO `user` (`region`, `account_id`, `summoner_id`, `summoner_name`) VALUES ('%s', %ld, %ld, '%s')", region, accountId, summonerId, summonerName);

	return result.AffectedRowsCount() != 0;
}