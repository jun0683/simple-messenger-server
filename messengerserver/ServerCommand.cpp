#include "StdAfx.h"
#include "ServerCommand.h"


CServerCommand::CServerCommand(boost::asio::io_service& io,MessengerServer_Ptr messengerServer)
	:m_io_service(io),m_messengerServer(messengerServer)
{

}


CServerCommand::~CServerCommand(void)
{
}

void CServerCommand::operator()()
{
	string inputCommand;

	while (true)
	{
		std::cout <<">>> ";
		std::getline(std::cin, inputCommand);
		if (!getCommand(inputCommand)->run(inputCommand,m_io_service,m_messengerServer))
			break;		
	}
}

ICommand_Ptr CServerCommand::getCommand(string &command)
{
	if (command == "exit")
	{
		return CExitCommand_Ptr(new CExitCommand);
	}
	else if(command == "status")
	{
		return CStatusComannd_Ptr(new CStatusComannd);
	}
	else
		return CNullCommand_Ptr(new	CNullCommand);
}