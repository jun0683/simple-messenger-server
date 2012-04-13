#pragma once

#include "UserInfo.h"
#include "UserManager.h"
#include "ServerParticipant.h"
class CUser :  public CServerParticipant, public boost::enable_shared_from_this<CUser>
{
public:
	CUser(boost::asio::io_service& io_service,CUserManager &userManager);
	virtual ~CUser(void);
	tcp::socket& socket()
	{
		return m_socket;
	}
	void start();
	void parsing(const boost::system::error_code& error,std::size_t bytes_transferred);
	void end(const boost::system::error_code& error);
private:
	boost::asio::ip::tcp::socket m_socket;
	UserInfo_Ptr m_userInfo;
	CUserManager &m_userManager;
	char buffer[1024];

};

typedef boost::shared_ptr<CUser> User_Ptr;
typedef std::list<User_Ptr> User_List;