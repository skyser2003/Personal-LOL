#pragma once

#include <memory>
#include <string>

namespace crow
{
	template <class ...>
	class Crow;

	template <typename ... Middlewares>
	using App = Crow<Middlewares...>;

	struct CookieParser;
}

class WebServer
{
public:
	explicit WebServer(int port);
	~WebServer();

	void Run();

	// Routes
	std::string Test();

private:
	int port;
	std::unique_ptr<crow::App<crow::CookieParser>> app;
};