#include "stdafx.h"
#include "WebServer.h"

#include <fstream>

WebServer::WebServer(int port, const std::string& rootPath) : port(port), app(new decltype(app)::element_type), rootPath(rootPath)
{
	auto& localApp = *app;
	localApp.port(port).multithreaded();

	CROW_ROUTE(localApp, "/")(std::bind(&WebServer::Index, this));
	CROW_ROUTE(localApp, "/<string>")(std::bind(&WebServer::Js, this, std::placeholders::_1));
}

WebServer::~WebServer()
{
}

void WebServer::Run()
{
	app->run();
}

std::string WebServer::Index() const
{
	auto filename = rootPath + "index.html";
	std::ifstream input(filename);
	std::string content{ std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>() };
	input.close();

	return content;
}

crow::response WebServer::Js(const std::string jsFilename) const
{
	auto filename = rootPath + jsFilename;
	std::ifstream input(filename);
	std::string content{ std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>() };
	input.close();

	crow::response r;
	r.add_header("Content-Type", "application/javascript");
	r.body = content;

	return r;
}

std::string WebServer::Css(const std::string cssFilename) const
{
	auto filename = rootPath + cssFilename;
	std::ifstream input(filename);
	std::string content{ std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>() };
	input.close();

	return content;
}
