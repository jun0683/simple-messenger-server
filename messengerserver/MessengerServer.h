#pragma once

#include "UserManager.h"
#include "User.h"
class CMessengerServer
{
public:
	CMessengerServer(boost::asio::io_service& io_service, const tcp::endpoint& endpoint);
	~CMessengerServer(void);

private:
	void	accept(User_Ptr user,const boost::system::error_code& error);
	void	newUserAccept(void);

private:
	boost::asio::io_service &m_io_service;
	tcp::acceptor m_acceptor;
	CUserManager m_userManager;
public:
	int		getCurrentUserCount(void);
	void	stopServer(void);
};

typedef boost::shared_ptr<CMessengerServer> MessengerServer_Ptr;