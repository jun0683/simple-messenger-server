#include "StdAfx.h"
#include "User.h"
#include "UserInfo.h"
#include "json_spirit.h"

using namespace json_spirit;

const mValue& find_value( const mObject& obj, const string& name  )
{
	mObject::const_iterator i = obj.find( name );

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
		
		string str(m_buffer.body(),m_buffer.body_length());
		tcout << "recv body :" << str << endl;
		paring(str);

		m_userManager.leaveUser(shared_from_this());
	}
}

void CUser::paring( string &str )
{
	mValue value;
	read(str,value);
	const mObject& obj = value.get_obj();
	int type1			=	find_value( obj,"type" ).get_int();
	string loginID		=	find_value( obj,"loginID").get_str();
	string password		=	find_value( obj,"password").get_str();
	string meessage		=	find_value( obj,"message").get_str();
}
