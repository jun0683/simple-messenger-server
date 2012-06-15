#include "StdAfx.h"
#include "User.h"
#include "UserInfo.h"
#include "DBManager.h"

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
	else
	{
		//m_userManager.leaveUser(shared_from_this());
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
	else
	{
		//m_userManager.leaveUser(shared_from_this());
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
	
	if (DBMgr->getUserInfo(loginID,password,*m_userInfo))
	{
		string name;
		encode_utf8(m_userInfo->userName,name);

		mObject obj;
		obj["type"] = LOGIN;
		obj["userID"] = m_userInfo->userID;
		obj["name"] = name;
		string writeStr = write(obj,raw_utf8);
		
		sendPacket(writeStr);
		tcout << L"write str: " << writeStr << endl;

		if(DBMgr->isUserLogin(m_userInfo->userID))
		{
			//m_userManager.leaveUser(m_userInfo->userID);
			DBMgr->userLogout(m_userInfo->userID);
		}
		
		if (DBMgr->userLogin(m_userInfo->userID))
		{
			//m_userManager.joinUser(shared_from_this());
			tcout << L"로그인 " << L"성공" << endl;
		}
		else
			tcout << L"로그인 " << L"실패" << endl;

	}
	else
	{
		tcout << L"입력된 정보가 잘못 되었습니다" << endl;
		//m_userManager.leaveUser(shared_from_this());
	}
}

void CUser::makeWriteBuffer( const string &writeStr )
{
	memcpy(m_writeBuffer.body(),writeStr.c_str(),writeStr.size());
	m_writeBuffer.body_length(writeStr.size());
	m_writeBuffer.encode_header();
}

void CUser::sendPacket( const string& packet )
{
	makeWriteBuffer(packet);

	boost::asio::async_write(m_socket,
		boost::asio::buffer(m_writeBuffer.data(), m_writeBuffer.length()),
		boost::bind( &CUser::readHeader, shared_from_this()));
}

void CUser::friendList()
{
	userinfos_ptr friends = DBMgr->userFriends(m_userInfo->userID);
	tcout << L"user " << m_userInfo->userID << L" friends" << endl;
	std::for_each(friends->begin(),friends->end(),[=](UserInfo_Ptr userinfo)
	{
		tcout << userinfo->userID << L" " << userinfo->loginID << L" " << userinfo->pw << L" " << userinfo->userName  << endl;
	});
}


void CUser::setUserID(int userID)
{

}

int CUser::getUserID()
{
	return 0;
}
