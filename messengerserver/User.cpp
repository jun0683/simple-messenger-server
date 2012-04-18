#include "StdAfx.h"
#include "User.h"
#include "UserInfo.h"




const wmValue& find_value( const wmObject& obj, const tstring& name  )
{
	wmObject::const_iterator i = obj.find( name );

	assert( i != obj.end() );
	assert( i->first == name );

	return i->second;
}


CUser::CUser(boost::asio::io_service& io_service,CUserManager &userManager)
	:m_socket(io_service),
	m_userManager(userManager),
	m_userInfo(new CUserInfo)
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
	int packetType	=	find_value( obj,L"type" ).get_int();
	switch(packetType)
	{
	case LOGIN:
		{
			if (login(obj))
				tcout ;
			else
				tcout ;

		}
		break;
	default:
		break;
	}
}

bool CUser::login( const wmObject& obj )
{
	tstring loginID		=	find_value( obj,L"loginID").get_str();
	tstring password	=	find_value( obj,L"password").get_str();
	CDBManager::getInstance()->getUserInfo(loginID,password,*m_userInfo);

	return false;
}
