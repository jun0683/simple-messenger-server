#pragma once

#include "UserInfo.h"

class CDBManager
{
public:
	CDBManager(void);
	~CDBManager(void);
	
	void			dbLogin(void);
	CUserInfo	getUserInfo(tstring loginID, tstring pw);
	bool			userLogin(int userID);
	bool			userLogout(int userID);
	bool			userLog(int userID,bool state);
	userinfos_ptr	userFriends(int userID);
};

