#include "stdafx.h"
#include "DataSaver.h"

DataSaver::DataSaver(const std::weak_ptr<DBConnection>& conn) : conn(conn)
{
}