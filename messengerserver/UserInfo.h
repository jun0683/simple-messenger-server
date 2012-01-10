#pragma once

class CUserInfo
{
public:
	int userID;
	string loginID;    
	string pw;
	string userName;
public:
	CUserInfo(void);
	~CUserInfo(void);
};

class UserInfoBCA //BCA : Bind Column Addresses
{
public:
	void operator()(BoundIOs &cols, CUserInfo &row)
	{
		cols[L"userID"]	>> row.userID;
		cols[L"loginID"]	>> row.loginID;
		cols[L"pw"]		>> row.pw;
		cols[L"userName"]	>> row.userName;
	}

};

class EmptyDataObj
{
};

class EmptyBCA
{
public:
	void operator()(BoundIOs &boundIOs, EmptyDataObj &rowbuf)	{}
};

//////////////////////////////////////////////////////////////////////////
/// BPA
/// Bind Params Addresses
//////////////////////////////////////////////////////////////////////////

class ParamUserInfo
{
public:
	tstring loginID;    
	tstring pw;
};

class UserInfoBPA 
{
public:
	void operator()(BoundIOs &params, ParamUserInfo &paramObj)
	{
		params[0] << paramObj.loginID;
		params[1] << paramObj.pw;
	}
};

class UserLog
{
public:
	int userID;
	bool logstate;
	bool logresult;
};

class UserLogBPA 
{
public:
	void operator()(BoundIOs &params, UserLog &paramObj)
	{
		params[0] << paramObj.userID;
		params[1] << paramObj.logstate;
		params[2] >> paramObj.logresult;

	}
};