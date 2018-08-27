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
	auto ComposeQuery(const std::string& query, const std::initializer_list<std::tuple<Args...>>& args) const
	{
		std::vector<std::string> batchElems;

		for (const auto& tuple : args)
		{
			auto strArgs = Escape(tuple);
			std::string batchElem = std::reduce(std::next(strArgs.begin()), strArgs.end(), *strArgs.begin(), &DBConnection::ConcatQueryArgs);

			batchElems.push_back("(" + batchElem + ")");
		}

		auto finalArg = std::reduce(std::next(batchElems.begin()), batchElems.end(), *batchElems.begin(), &DBConnection::ConcatQueryArgs);

		return (boost::format(query) % finalArg).str();
	}

	template <typename ...Args>
	auto ComposeQuery(const std::string& query, const std::vector<std::tuple<Args...>>& args) const
	{
		std::vector<std::string> batchElems;

		for (const auto& tuple : args)
		{
			auto strArgs = Escape(tuple);
			std::string batchElem = std::reduce(std::next(strArgs.begin()), strArgs.end(), *strArgs.begin(), &DBConnection::ConcatQueryArgs);

			batchElems.push_back("(" + batchElem + ")");
		}

		auto finalArg = std::reduce(std::next(batchElems.begin()), batchElems.end(), *batchElems.begin(), &DBConnection::ConcatQueryArgs);

		return (boost::format(query) % finalArg).str();
	}

private:
	static std::string ConcatQueryArgs(const std::string& arg1, const std::string& arg2);

	std::string Escape(const char* arg) const;
	std::string Escape(const std::string& arg) const;

	std::string EscapeTupleElem(const char* arg) const;
	std::string EscapeTupleElem(const std::string& arg) const;

	template <typename ...Args>
	auto Escape(const std::tuple<Args...>& tuple) const
	{
		return EscapeTuple(std::index_sequence_for<Args...>(), tuple);
	}

	template <typename ArgType>
	auto Escape(ArgType arg) const
	{
		const auto strArg = std::to_string(arg);
		return Escape(strArg);
	}

	template <std::size_t... Index, typename ...Args>
	auto EscapeTuple(std::index_sequence<Index...>, const std::tuple<Args...>& tuple) const
	{
		return std::vector{ EscapeTupleElem(std::get<Index>(tuple))... };
	}

	template <typename ArgType>
	auto EscapeTupleElem(ArgType arg) const
	{
		return Escape(arg);
	}

	const DBInfo info;
	MYSQL& conn;
};