#pragma once

#include "UserInfo.h"
#include "UserManager.h"
#include "IUser.h"
#include "DataBuffer.h"
class CUser :  public IUser, public boost::enable_shared_from_this<CUser>
{
public:
	CUser(boost::asio::io_service& io_service,CUserManager &userManager);
	virtual ~CUser(void);
	tcp::socket& socket()
	{
		return m_socket;
	}
	void start();
	void handleReadHeader(const boost::system::error_code& error);
	void handleReadBody(const boost::system::error_code& error);
private:
	boost::asio::ip::tcp::socket m_socket;
	UserInfo_Ptr m_userInfo;
	CUserManager &m_userManager;
	CDataBuffer m_buffer;

};

typedef boost::shared_ptr<CUser> User_Ptr;
typedef std::list<User_Ptr> User_List;