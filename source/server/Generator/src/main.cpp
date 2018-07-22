#include "stdafx.h"
#include "Server.h"

int main()
{
	Server server(9999);
	server.Run();

	system("pause");
	return 0;
}