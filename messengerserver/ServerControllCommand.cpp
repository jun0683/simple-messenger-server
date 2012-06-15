#include "StdAfx.h"
#include "ServerControllCommand.h"


CServerControllCommand::CServerControllCommand(boost::asio::io_service& io,MessengerServer_Ptr messengerServer)
	:m_io_service(io),m_messengerServer(messengerServer)
{

}


CServerControllCommand::~CServerControllCommand(void)
{
}

void CServerControllCommand::operator()()
{
	string inputCommand;

	while (true)
	{
		std::cout <<">>> ";
		std::getline(std::cin, inputCommand);
		if (ICommand_Ptr command = getCommand(inputCommand))
		{
			if (!command->run(m_messengerServer))
				break;
		}
			
	}
}

ICommand_Ptr CServerControllCommand::getCommand(string &command)
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