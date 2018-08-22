#include "stdafx.h"
#include "DataSaver.h"

#include "ApiResultStruct.h"
#include "DBConnection.h"

using namespace RiotApi;

DataSaver::DataSaver(const std::shared_ptr<DBConnection>& conn) : conn(conn)
{
}

bool DataSaver::RegisterUser(const std::string& region, long accountId, long summonerId, const std::string& summonerName)
{
	const auto result = conn->WriteQuery("INSERT INTO `user` (`region`, `account_id`, `summoner_id`, `summoner_name`, `register_date`, `update_date`) VALUES ('%s', %ld, %ld, '%s', NOW(), NOW()) ON DUPLICATE KEY UPDATE `update_date` = VALUES(`update_date`)", region, accountId, summonerId, summonerName);

	return result.AffectedRowsCount() != 0;
}

bool DataSaver::SaveMatchResults(const std::vector<MatchReferenceDto>& apiResult)
{
	const auto result = conn->WriteQuery("INSERT IGNORE INTO `match` (`match_id`, `champion`, `lane`, `platform_id`, `queue`, `role`, `season`, `timestamp`) VALUES (%ld, %d, '%s', '%s', %d, '%s', %d, %d)");

	return result.AffectedRowsCount() != 0;
}