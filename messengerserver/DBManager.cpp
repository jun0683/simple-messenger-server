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

int CDBManager::login( tstring loginID, tstring pw )
{
	DBView<CUserInfo,ParamUserInfo> view(L"{call login(?,?)}", UserInfoBCA(),L"",UserInfoBPA());
	DBView<CUserInfo, ParamUserInfo>::sql_iterator print_it = view;
	print_it.Params().loginID = loginID;
	print_it.Params().pw = pw;
	*print_it = CUserInfo(); // force the statement to execute 
	++print_it;

	return print_it->userID;
	
}
