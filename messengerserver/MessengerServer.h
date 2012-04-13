#pragma once

#include "UserManager.h"
#include "User.h"
class CMessengerServer
{
public:
	CMessengerServer(boost::asio::io_service& io_service, const tcp::endpoint& endpoint);
	~CMessengerServer(void);
	
private:
	boost::asio::io_service &m_io_service;
	tcp::acceptor m_acceptor;
	CUserManager m_userManager;
public:
	void accept(User_Ptr user,const boost::system::error_code& error);
	int Run(void);
	void newUserAccept(void);
};

typedef boost::shared_ptr<CMessengerServer> MessengerServer_Ptr;