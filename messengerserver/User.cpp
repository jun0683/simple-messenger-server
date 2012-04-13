#include "StdAfx.h"
#include "User.h"
#include "UserInfo.h"
#include "json_spirit.h"


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

	boost::asio::async_read(m_socket,
		boost::asio::buffer(m_buffer.data(), CDataBuffer::header_length),
		boost::bind( &CUser::handleReadHeader, shared_from_this(),
		boost::asio::placeholders::error));

}


void CUser::handleReadHeader(const boost::system::error_code& error)
{
	if (!error && m_buffer.decode_header())
	{
		m_buffer.encode_header();
		boost::asio::async_read(m_socket,
			boost::asio::buffer(m_buffer.body(),m_buffer.body_length()),
			boost::bind(&CUser::handleReadBody, shared_from_this(),
			boost::asio::placeholders::error));
	}
}

void CUser::handleReadBody(const boost::system::error_code& error)
{
	if (!error)
	{
		

		tcout << "recv body :" << str << endl;
		m_userManager.leaveUser(shared_from_this());
	}
}