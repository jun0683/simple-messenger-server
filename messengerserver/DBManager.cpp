#include "StdAfx.h"
#include "DBManager.h"
#include "UserInfo.h"

CDBManager::CDBManager(void)
{
}


CDBManager::~CDBManager(void)
{
	DBConnection::GetDefaultConnection().Release();
}


void CDBManager::dbLogin(void)
{
	DBConnection::GetDefaultConnection().Connect(DNSSTR);
	if (DBConnection::GetDefaultConnection().GetDBMSEnum() == DBConnection::DB_SQL_SERVER) 
	{

		
	}
}

CUserInfo CDBManager::getUserInfo( tstring loginID, tstring pw )
{
	DBView<CUserInfo,ParamUserInfo> view(L"{call getUserInfo(?,?)}", UserInfoBCA(),L"",UserInfoBPA());
	DBView<CUserInfo, ParamUserInfo>::sql_iterator print_it = view;
	print_it.Params().loginID = loginID;
	print_it.Params().pw = pw;
	*print_it = CUserInfo(); // force the statement to execute
	return *print_it;
}


bool CDBManager::userLogin(int userID)
{
	return userLog(userID,1);
}

bool CDBManager::userLogout(int userID)
{
	return userLog(userID,0);
}

bool CDBManager::userLog(int userID,bool state)
{
	DBView<EmptyDataObj, UserLog> view(L"{call insertLog(?,?,?)}", EmptyBCA(),L"",UserLogBPA());
	DBView<EmptyDataObj, UserLog>::sql_iterator print_it = view;
	print_it.Params().userID = userID;
	print_it.Params().logstate = state;
	*print_it = EmptyDataObj();
	print_it.MoreResults();
	
	return print_it.Params().logresult;
}