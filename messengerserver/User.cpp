#include "StdAfx.h"
#include "User.h"
#include "UserInfo.h"


CUser::CUser(boost::asio::io_service& io_service,CUserManager &userManager)
	:m_socket(io_service),
	m_userManager(userManager)
{
}


CUser::~CUser(void)
{

}

void CUser::start()
{
	m_userManager.joinUser(shared_from_this());

	ZeroMemory(buffer,1024);
	m_socket.async_read_some(boost::asio::buffer(buffer, 1024),
		boost::bind( &CUser::parsing, shared_from_this(),
		boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
//	boost::asio::async_read_some(m_socket,
//		boost::asio::buffer(buffer, 1024),
//		boost::bind( &CUser::parsing, shared_from_this(),
//		boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
//
}


void CUser::parsing(const boost::system::error_code& error,std::size_t bytes_transferred)
{
	tcout << buffer << endl;

	boost::asio::async_write(m_socket,
		boost::asio::buffer(buffer,bytes_transferred),
		boost::bind(&CUser::end, shared_from_this(),
		boost::asio::placeholders::error));
}

void CUser::end(const boost::system::error_code& error)
{
	m_userManager.leaveUser(shared_from_this());
}