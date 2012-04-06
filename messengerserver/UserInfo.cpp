#include "StdAfx.h"
#include "UserInfo.h"

CUserInfo::CUserInfo(void)
	:userID(-1)
{
}

CUserInfo::CUserInfo(int _userID,tstring _loginID,tstring _pw,tstring _userName)
	:userID(_userID),loginID(_loginID),pw(_pw),userName(_userName)
{
	
}

CUserInfo::~CUserInfo(void)
{
}

