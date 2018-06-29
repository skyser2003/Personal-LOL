#pragma once

#include <memory>

class DBConnection;

class DataSaver
{
public:
	DataSaver(const std::weak_ptr<DBConnection>& conn);

private:
	std::weak_ptr<DBConnection> conn;
};