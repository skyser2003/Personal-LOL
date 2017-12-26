#include "stdafx.h"
#include "Server.h"

namespace HttpServer
{
	Server::Server(boost::asio::io_context& ioc)
		: acc(ioc), soc(ioc)
	{
	}

	void Server::listen(boost::asio::ip::tcp::endpoint end)
	{
		boost::system::error_code ec;

		acc.open(end.protocol(), ec);
		if(ec)
		{
			return;
		}

		acc.bind(end, ec);
		if(ec)
		{
			return;
		}

		acc.listen(boost::asio::socket_base::max_listen_connections, ec);
		if(ec)
		{
			return;
		}


	}
}
/*
class listener : public std::enable_shared_from_this<listener>
{
	tcp::acceptor acceptor_;
	tcp::socket socket_;
	std::string const& doc_root_;

public:
	listener(
		boost::asio::io_context& ioc,
		tcp::endpoint endpoint,
		std::string const& doc_root)
		: acceptor_(ioc)
		, socket_(ioc)
		, doc_root_(doc_root)
	{
		boost::system::error_code ec;

		// Open the acceptor
		acceptor_.open(endpoint.protocol(), ec);
		if (ec)
		{
			fail(ec, "open");
			return;
		}

		// Bind to the server address
		acceptor_.bind(endpoint, ec);
		if (ec)
		{
			fail(ec, "bind");
			return;
		}

		// Start listening for connections
		acceptor_.listen(
			boost::asio::socket_base::max_listen_connections, ec);
		if (ec)
		{
			fail(ec, "listen");
			return;
		}
	}

	// Start accepting incoming connections
	void
		run()
	{
		if (!acceptor_.is_open())
			return;
		do_accept();
	}

	void
		do_accept()
	{
		acceptor_.async_accept(
			socket_,
			std::bind(
				&listener::on_accept,
				shared_from_this(),
				std::placeholders::_1));
	}

	void
		on_accept(boost::system::error_code ec)
	{
		if (ec)
		{
			fail(ec, "accept");
		}
		else
		{
			// Create the session and run it
			std::make_shared<session>(
				std::move(socket_),
				doc_root_)->run();
		}

		// Accept another connection
		do_accept();
	}
};
*/