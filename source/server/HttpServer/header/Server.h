#pragma once

#include <boost/beast.hpp>

namespace HttpServer
{
	class Server
	{
	public:
		explicit Server(boost::asio::io_context& ioc);

		void listen(boost::asio::ip::tcp::endpoint end);

	private:
		boost::asio::ip::tcp::acceptor acc;
		boost::asio::ip::tcp::socket soc;
	};
}