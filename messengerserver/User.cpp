#include "StdAfx.h"
#include "User.h"
#include "UserInfo.h"
#include "json_spirit.h"

using namespace json_spirit;

const wmValue& find_value( const wmObject& obj, const tstring& name  )
{
	wmObject::const_iterator i = obj.find( name );

	assert( i != obj.end() );
	assert( i->first == name );

	return i->second;
}


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
		
		tstring bufferStr(m_buffer.body(),m_buffer.body()+m_buffer.body_length());
		tcout << "recv body :" << bufferStr << endl;

		paring(bufferStr);

		m_userManager.leaveUser(shared_from_this());
	}
}

void CUser::paring( tstring &str )
{
	wmValue value;
	read(str,value);
	const wmObject& obj = value.get_obj();
	int type1			=	find_value( obj,L"type" ).get_int();
	tstring loginID		=	find_value( obj,L"loginID").get_str();
	tstring password	=	find_value( obj,L"password").get_str();
	tstring message		=	find_value( obj,L"message").get_str();
	tcout << "parsing " << endl;
	tcout << message << endl;
}
