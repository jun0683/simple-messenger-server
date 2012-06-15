#pragma once

#include "MessengerServer.h"

class ICommand
{
public:
	ICommand(void);
	~ICommand(void);
	virtual bool run(MessengerServer_Ptr server) = 0;
};


class CNullCommand : public ICommand
{
public:
	virtual bool run(MessengerServer_Ptr server)
	{
		return true;
	};
};


class CStatusComannd: public ICommand
{
public:
	virtual bool run(MessengerServer_Ptr server)
	{
		tcout << "current User : " << server->getCurrentUserCount() << endl;
		return true;
	}
};

class CExitCommand : public ICommand
{
public:
	virtual bool run(MessengerServer_Ptr server)
	{
		server->stopServer();
		return false;
	}
};

typedef boost::shared_ptr<ICommand> ICommand_Ptr;
typedef boost::shared_ptr<CNullCommand> CNullCommand_Ptr;
typedef boost::shared_ptr<CStatusComannd> CStatusComannd_Ptr;
typedef boost::shared_ptr<CExitCommand> CExitCommand_Ptr;


