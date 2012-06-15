#include "StdAfx.h"
#include "MessengerServer.h"


CMessengerServer::CMessengerServer(boost::asio::io_service& io_service, const tcp::endpoint& endpoint)
	:m_acceptor(io_service,endpoint),
	m_io_service(io_service)
{
	
	newUserAccept();
}


CMessengerServer::~CMessengerServer(void)
{
}

void CMessengerServer::accept(User_Ptr user,const boost::system::error_code& error)
{
	if (!error)
	{
		user->start();
		newUserAccept();
		std::string remote_ip = user->socket().remote_endpoint().address().to_string();
		unsigned short remote_port = user->socket().remote_endpoint().port();
		cout << "Client connected : " << remote_ip.c_str() << " : " << remote_port << endl;
	}
	else
		tcout << "error : " << error.value() << endl;
	
}

void CMessengerServer::newUserAccept(void)
{
	User_Ptr new_user(new CUser(m_io_service, m_userManager));
	/*m_acceptor.async_accept(new_user->socket(),
		boost::bind(&CMessengerServer::accept, this, new_user,boost::asio::placeholders::error));*/
	
	//new_user는 copy 하면서 count++ 이 됨 
	m_acceptor.async_accept(new_user->socket(),[=](const boost::system::error_code& error)
	{
		if (!error)
		{
			new_user->start();
			newUserAccept();
			std::string remote_ip = new_user->socket().remote_endpoint().address().to_string();
			unsigned short remote_port = new_user->socket().remote_endpoint().port();
			cout << "Client connected : " << remote_ip.c_str() << " : " << remote_port << endl;
		}
		else
		{
			tcout << "error : " << error.message() << " , " << error.value() << endl;
		}
	});
}


int CMessengerServer::getCurrentUserCount(void)
{
	return m_userManager.getCurrentUserCount();
}


void CMessengerServer::stopServer(void)
{
	m_io_service.stop();
}
