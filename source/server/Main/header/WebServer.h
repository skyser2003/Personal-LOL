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
	explicit WebServer(int port, const std::string& rootPath);
	~WebServer();

	void Run();

	// Routes
	std::string Index() const;

	// Static files
	crow::response Js(const std::string jsFilename) const;
	std::string Css(const std::string cssFilename) const;

private:
	int port;
	std::unique_ptr<crow::App<crow::CookieParser>> app;

	std::string rootPath;
};