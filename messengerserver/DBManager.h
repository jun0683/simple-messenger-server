#pragma once

class CUserInfo;

class CDBManager
{
public:
	CDBManager(void);
	~CDBManager(void);
	void dbLogin(void);
	CUserInfo getUserInfo(tstring loginID, tstring pw);
	bool userLogin(int userID);
	bool userLogout(int userID);
	bool CDBManager::userLog(int userID,bool state);
};

