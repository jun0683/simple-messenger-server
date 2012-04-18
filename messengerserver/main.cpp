#include "StdAfx.h"
#include "DBManager.h"
#include "Timer.h"
#include "UserInfo.h"
#include "testDBCode.h"
#include "MessengerServer.h"


int PORT = 50000;


int main(int argc, char* argv[])
{
	try
	{
		//dbtest();
		setlocale(LC_ALL, "");
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::endpoint endpoint(tcp::v4(), PORT);
		vector<MessengerServer_Ptr> serverArray;
		MessengerServer_Ptr server(new CMessengerServer(io_service,endpoint));
		serverArray.push_back(server);
		io_service.run();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	return 0;
}

