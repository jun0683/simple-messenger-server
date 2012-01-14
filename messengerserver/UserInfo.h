#pragma once

class CUserInfo
{
public:
	int userID;
	tstring loginID;    
	tstring pw;
	tstring userName;
public:
	CUserInfo(void);
	CUserInfo(int userID,tstring loginID,tstring pw,tstring userName);
	~CUserInfo(void);
};
typedef shared_ptr<CUserInfo> userInfo_ptr;
typedef vector<userInfo_ptr> userInfos;
typedef shared_ptr<userInfos> userinfos_ptr;

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
	void operator()(BoundIOs &cols, EmptyDataObj &rowbuf)	{}
};

class UserLoginStateBCA
{
public:
	void operator()(BoundIOs &cols, variant_row &row)	
	{
		cols[0] >> row._int(); //return
		cols[1] << row._int(); //userid
		cols.BindVariantRow(row);
	}
};

class ChattingRoomMakeBCA
{
public:
	void operator()(BoundIOs &cols, variant_row &row)	
	{
		cols[0] >> row._int(); //return
		cols[1] << row._int(); // userID
		cols.BindVariantRow(row);
	}
};


class ChattingRoomStateBPA
{
public:
	void operator()(BoundIOs &cols,variant_row &row )
	{
		cols[0] << row._int(); //roomnumber
		cols[1] << row._int(); //userid
		cols[2] << row._bool();//state
		cols.BindVariantRow(row);
	}
};

class ChattingMessageBPA
{
public:
	void operator()(BoundIOs &cols,variant_row &row )
	{
		cols[0] << row._int(); //roomnumber
		cols[1] << row._int(); //userid
		cols[2] << row._tstring();//state
		cols.BindVariantRow(row);
	}
};

class RegisterUserBPA
{
public:
	void operator()(BoundIOs &cols,variant_row &row )
	{
		cols[0] >> row._int(); //return
		cols[1] << row._tstring(); //userloginid
		cols[2] << row._tstring(); //userloginpw
		cols.BindVariantRow(row);
	}
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

class ParamUserLog
{
public:
	int userID;
	bool logState;
	bool logResult;
};

class UserLogBPA 
{
public:
	void operator()(BoundIOs &params, ParamUserLog &paramObj)
	{
		params[0] << paramObj.userID;
		params[1] << paramObj.logState;
		params[2] >> paramObj.logResult;

	}
};

class ParamUserID
{
public:
	int userID;
};


class UserIDBPA 
{
public:
	void operator()(BoundIOs &params, ParamUserID &paramObj)
	{
		params[0] << paramObj.userID;
	}	
};

