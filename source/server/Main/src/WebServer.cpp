#include "stdafx.h"
#include "WebServer.h"

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

std::string WebServer::Test()
{
	return "boo";
}
