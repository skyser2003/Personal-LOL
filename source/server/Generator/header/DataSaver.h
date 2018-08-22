#pragma once

#include <memory>
#include <vector>

namespace RiotApi
{
	struct MatchReferenceDto;
}

class DBConnection;

class DataSaver
{
public:
	DataSaver(const std::shared_ptr<DBConnection>& conn);

	bool RegisterUser(const std::string& region, long accountId, long summonerId, const std::string& summonerName);
	bool SaveMatchResults(const std::vector<RiotApi::MatchReferenceDto>& apiResult);

private:
	std::shared_ptr<DBConnection> conn;
};