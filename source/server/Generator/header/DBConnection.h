#pragma once

#include <vector>
#include <tuple>

#include <boost/format.hpp>
#include "mysql.h"

#include "DBReadResult.h"
#include "DBWriteResult.h"

struct DBInfo
{
	std::string host;
	std::string db;
	std::string user;
	std::string pw;
};

class DBConnection
{
public:
	DBConnection(const DBInfo& info);
	~DBConnection();

	bool Connect(int retryCount, int retrySleepMs = 5000);

	DBReadResult ReadQuery(const std::string& query);

	template <typename ...Args>
	auto ReadQuery(const std::string& query, Args... args)
	{
		return ReadQuery(ComposeQuery(query, args...));
	}

	DBWriteResult WriteQuery(const std::string& query);

	template <typename ...Args>
	auto WriteQuery(const std::string& query, Args... args)
	{
		return WriteQuery(ComposeQuery(query, args...));
	}

	template <typename ...Args>
	auto ComposeQuery(const std::string& query, Args... args) const
	{
		return (boost::format(query) % ... % Escape(args)).str();
	}

	template <typename ...Args>
	auto ComposeQuery(const std::string& query, const std::vector<std::tuple<Args...>>& args) const
	{
		return "";
	}

private:
	template <typename ArgType>
	auto Escape(ArgType arg) const
	{
		const auto strArg = std::to_string(arg);
		return Escape(strArg);
	}

	template <>
	auto Escape(const char* arg) const
	{
		return Escape(std::string(arg));
	}

	std::string Escape(const std::string& arg) const;

	const DBInfo info;
	MYSQL& conn;
};