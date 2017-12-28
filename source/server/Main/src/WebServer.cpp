#include "stdafx.h"
#include "WebServer.h"

#include <fstream>

WebServer::WebServer(int port) : port(port), app(new decltype(app)::element_type)
{
	app->port(port).multithreaded();

	auto& localApp = *app;
	CROW_ROUTE(localApp, "/test")(std::bind(&WebServer::Test, this));
}

WebServer::~WebServer()
{
}

void WebServer::Run()
{
	app->run();
}

std::string WebServer::Test() const
{
	auto filename = "html/template/main.mustache";
	std::ifstream input(filename);
	std::string content {std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};
	input.close();

	auto t = crow::mustache::compile(content);

	crow::mustache::context ctx;
	ctx["name"] = "Pikachu";

	return t.render(ctx);
}
