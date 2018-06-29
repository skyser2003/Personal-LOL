#include "stdafx.h"
#include "DataSaver.h"

#include "DBConnection.h"

DataSaver::DataSaver(const std::shared_ptr<DBConnection>& conn) : conn(conn)
{
}

void DataSaver::RegisterUser(const std::string& summonerName)
{
}