#include "StdAfx.h"
#include "DBManager.h"
#include "Timer.h"
#include "UserInfo.h"
#include "testDBCode.h"
#include "MessengerServer.h"


int PORT = 50000;


class CInput
{
public:
	CInput(boost::asio::io_service& io)
		:m_io_service(io)
	{

	};
	void operator()()
	{
		string inputbuffer;

		while (true)
		{
			std::cout <<">>> ";
			std::getline(std::cin, inputbuffer);
			if (inputbuffer == "exit")
			{
				m_io_service.stop();
				break;;
			}
		}
	}
	~CInput(){};
private:
	boost::asio::io_service& m_io_service;
};


int main(int argc, char* argv[])
{
	try
	{
		setlocale(LC_ALL, "");

		boost::asio::io_service io_service;
		boost::asio::ip::tcp::endpoint endpoint(tcp::v4(), PORT);

		vector<MessengerServer_Ptr> serverArray;

		MessengerServer_Ptr server(new CMessengerServer(io_service,endpoint));
		serverArray.push_back(server);

		CInput input(io_service);
		boost::thread inputThread(input);

		io_service.run();
		inputThread.join();
		
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	return 0;
}

