#pragma once

#include "MessengerServer.h"
#include "ICommand.h"

class CServerCommand
{
public:
	CServerCommand(boost::asio::io_service& io,MessengerServer_Ptr messengerServer);
	~CServerCommand(void);
	void operator()();
	ICommand_Ptr getCommand(string &command);
private:
	boost::asio::io_service& m_io_service;
	MessengerServer_Ptr m_messengerServer;
};

