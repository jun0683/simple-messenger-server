#pragma once

//////////////////////////////////////////////////////////////////////////
/// BCA 
/// Bind Column Addresses
//////////////////////////////////////////////////////////////////////////

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

class UserInfoBCA 
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

class UserIDObj
{
public:
	int userID;
};

class UserIDBCA
{
public:
	void operator()(BoundIOs &cols, UserIDObj &row)
	{
		cols[L"userID"]	>> row.userID;
	}
};

class EmptyDataObj
{
};

class EmptyBCA
{
public:
	void operator()(BoundIOs &cols, EmptyDataObj &row)	
	{
		//cols.BindAsBase(row);
	}
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


class ChattingRoomStateBCA
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

class ChattingMessageBCA
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

class RegisterUserBCA
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

class DidFriendsRequst
{
public:
	int userID;
};

class DidFriendsRequstBCA
{
public:
	void operator()(BoundIOs &cols, DidFriendsRequst &row)
	{
		cols[L"userID"]	>> row.userID;
	}
};

class FindUserID
{
public:
	int userID;
};

class FindUserIDBCA 
{
public:
	void operator()(BoundIOs &cols, FindUserID &row)
	{
		cols[L"userID"]	>> row.userID;
	}
};

//////////////////////////////////////////////////////////////////////////
/// BPA
/// Bind Params Addresses
//////////////////////////////////////////////////////////////////////////

class IDAndPWObj
{
public:
	int returnvalue;
	tstring loginID;    
	tstring pw;
};

class UserInfoBPA 
{
public:
	void operator()(BoundIOs &params, IDAndPWObj &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.loginID;
		params[2] << paramObj.pw;
	}
};

class GetUserID
{
public:
	int returnvalue;
	tstring loginID;    
};

class GetUserIDBPA 
{
public:
	void operator()(BoundIOs &params, GetUserID &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.loginID;
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


class UserObj
{
public:
	int returnvalue;
	tstring userloginID;
	tstring userloginPW;
	tstring userName;
};

class UserBPA
{
public:
	void operator()(BoundIOs &cols,UserObj &params )
	{
		cols[0] >> params.returnvalue; //return
		cols[1] << params.userloginID; //userloginid
		cols[2] << params.userloginPW; //userloginpw
		cols[3] << params.userName;
	}
};

class ValidUserObj
{
public:
	int returnvalue;
	tstring userloginID;
};

class ValidUserBPA
{
public:
	void operator()(BoundIOs &cols,ValidUserObj &params )
	{
		cols[0] >> params.returnvalue; //return
		cols[1] << params.userloginID; //userloginid
	}
};


class WithdrawObj
{
public:
	int returnvalue;
	tstring userloginID;    
	tstring userloginPW;
};

class WithdrawBPA
{
public:
	void operator()(BoundIOs &params, WithdrawObj &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userloginID;
		params[2] << paramObj.userloginPW;
	}
};

class AddFriendRequest
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class AddFriendRequestBPA
{
public:
	void operator()(BoundIOs &params, AddFriendRequest &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};

class DidFriendsRequstParamObj
{
public:
	int returnvalue;
	int friendID;
};

class DidFriendsRequstBPA
{
public:
	void operator()(BoundIOs &params, DidFriendsRequstParamObj &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.friendID;
	}
};

class AddFriendRespond
{
public:
	int returnvalue;
	int userID;    
	int friendID;
	int respond;
};

class AddFriendRespondBPA
{
public:
	void operator()(BoundIOs &params, AddFriendRespond &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
		params[3] << paramObj.respond;
	}
};


class AddFriend
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class AddFriendBPA
{
public:
	void operator()(BoundIOs &params, AddFriend &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};



class DelFriendRequest
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class DelFriendRequestBPA
{
public:
	void operator()(BoundIOs &params, DelFriendRequest &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};

class FindUser
{
public:
	int returnvalue;
	tstring userloginID;
};

class FindUserBPA
{
public:
	void operator()(BoundIOs &params, FindUser &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userloginID;
		
	}
};

class DelFriend
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class DelFriendBPA
{
public:
	void operator()(BoundIOs &params, DelFriend &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};