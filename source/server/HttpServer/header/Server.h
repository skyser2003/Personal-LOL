#pragma once

namespace HttpServer
{
	class Server
	{
	public:
		explicit Server(int port);

		void run();

	private:
		int port;
	};
}