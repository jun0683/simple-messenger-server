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

	readHeader();
}

void CUser::readHeader()
{
	boost::asio::async_read(m_socket,
		boost::asio::buffer(m_readBuffer.data(), CDataBuffer::header_length),
		boost::bind( &CUser::handleReadHeader, shared_from_this(),
		boost::asio::placeholders::error));
}

void CUser::handleReadHeader(const boost::system::error_code& error)
{
	if (!error && m_readBuffer.decode_header())
	{
		m_readBuffer.encode_header();
		boost::asio::async_read(m_socket,
			boost::asio::buffer(m_readBuffer.body(),m_readBuffer.body_length()),
			boost::bind(&CUser::handleReadBody, shared_from_this(),
			boost::asio::placeholders::error));
	}
}

void CUser::handleReadBody(const boost::system::error_code& error)
{
	if (!error)
	{
		
		tstring bufferStr(m_readBuffer.body(),m_readBuffer.body()+m_readBuffer.body_length());
		tcout << "recv body :" << endl << bufferStr << endl;

		paring(bufferStr);
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
			login(obj);
		break;
	default:
		break;
	}
}

void CUser::login( const wmObject& obj )
{
	tstring loginID		=	find_value( obj,L"loginID").get_str();
	tstring password	=	find_value( obj,L"password").get_str();

	if (CDBManager::getInstance()->getUserInfo(loginID,password,*m_userInfo))
	{
		mObject obj;

		obj["session" ] = 1;
		obj["type"] = 1;
		tstring wname = m_userInfo->userName;
		string name;
		encode_utf8(wname,name);
		obj["message"] = name;
		string writeStr = write(obj);
		/*string writeStr;
		encode_utf8(ws, writeStr);*/


		memcpy(m_writeBuffer.body(),writeStr.c_str(),writeStr.size());
		m_writeBuffer.body_length(writeStr.size());
		m_writeBuffer.encode_header();
		boost::asio::async_write(m_socket,
			boost::asio::buffer(m_writeBuffer.data(), m_writeBuffer.length()),
			boost::bind( &CUser::readHeader, shared_from_this()));
		tcout << L"로그인 성공" << endl;
		tcout << writeStr << endl;
	}
	else
	{
		tcout << L"로그인 실패" << endl;
		m_userManager.leaveUser(shared_from_this());
	}
}