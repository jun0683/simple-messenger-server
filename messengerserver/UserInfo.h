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
typedef boost::shared_ptr<CUserInfo> UserInfo_Ptr;
typedef vector<UserInfo_Ptr> userInfos;
typedef boost::shared_ptr<userInfos> userinfos_ptr;

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

class UserIDRow
{
public:
	int userID;
};

class UserIDBCA
{
public:
	void operator()(BoundIOs &cols, UserIDRow &row)
	{
		cols[L"userID"]	>> row.userID;
	}
};

class EmptyRow
{
};

class EmptyBCA
{
public:
	void operator()(BoundIOs &cols, EmptyRow &row)	
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

class DidFriendsRequstRow
{
public:
	int userID;
};

class DidFriendsRequstBCA
{
public:
	void operator()(BoundIOs &cols, DidFriendsRequstRow &row)
	{
		cols[L"userID"]	>> row.userID;
	}
};

class FindUserIDRow
{
public:
	int userID;
};

class FindUserIDBCA 
{
public:
	void operator()(BoundIOs &cols, FindUserIDRow &row)
	{
		cols[L"userID"]	>> row.userID;
	}
};

//////////////////////////////////////////////////////////////////////////
/// BPA
/// Bind Params Addresses
//////////////////////////////////////////////////////////////////////////

class IDAndPWParams
{
public:
	int returnvalue;
	tstring loginID;    
	tstring pw;
};

class UserInfoBPA 
{
public:
	void operator()(BoundIOs &params, IDAndPWParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.loginID;
		params[2] << paramObj.pw;
	}
};

class GetUserIDParams
{
public:
	int returnvalue;
	tstring loginID;    
};

class GetUserIDBPA 
{
public:
	void operator()(BoundIOs &params, GetUserIDParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.loginID;
	}
};

class UserLogParams
{
public:
	int userID;
	bool logState;
	bool logResult;
};

class UserLogBPA 
{
public:
	void operator()(BoundIOs &params, UserLogParams &paramObj)
	{
		params[0] << paramObj.userID;
		params[1] << paramObj.logState;
		params[2] >> paramObj.logResult;

	}
};

class UserIDParams
{
public:
	int userID;
};


class UserIDBPA 
{
public:
	void operator()(BoundIOs &params, UserIDParams &paramObj)
	{
		params[0] << paramObj.userID;
	}	
};


class UserParams
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
	void operator()(BoundIOs &cols,UserParams &params )
	{
		cols[0] >> params.returnvalue; //return
		cols[1] << params.userloginID; //userloginid
		cols[2] << params.userloginPW; //userloginpw
		cols[3] << params.userName;
	}
};

class ValidUserParams
{
public:
	int returnvalue;
	tstring userloginID;
};

class ValidUserBPA
{
public:
	void operator()(BoundIOs &cols,ValidUserParams &params )
	{
		cols[0] >> params.returnvalue; //return
		cols[1] << params.userloginID; //userloginid
	}
};


class WithdrawParams
{
public:
	int returnvalue;
	tstring userloginID;    
	tstring userloginPW;
};

class WithdrawBPA
{
public:
	void operator()(BoundIOs &params, WithdrawParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userloginID;
		params[2] << paramObj.userloginPW;
	}
};

class AddFriendRequestParams
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class AddFriendRequestBPA
{
public:
	void operator()(BoundIOs &params, AddFriendRequestParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};

class DidFriendsRequstParams
{
public:
	int returnvalue;
	int friendID;
};

class DidFriendsRequstBPA
{
public:
	void operator()(BoundIOs &params, DidFriendsRequstParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.friendID;
	}
};

class AddFriendRespondParams
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
	void operator()(BoundIOs &params, AddFriendRespondParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
		params[3] << paramObj.respond;
	}
};


class AddFriendParams
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class AddFriendBPA
{
public:
	void operator()(BoundIOs &params, AddFriendParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};



class DelFriendRequestParams
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class DelFriendRequestBPA
{
public:
	void operator()(BoundIOs &params, DelFriendRequestParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};

class FindUserParams
{
public:
	int returnvalue;
	tstring userloginID;
};

class FindUserBPA
{
public:
	void operator()(BoundIOs &params, FindUserParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userloginID;
		
	}
};

class DelFriendParams
{
public:
	int returnvalue;
	int userID;    
	int friendID;
};

class DelFriendBPA
{
public:
	void operator()(BoundIOs &params, DelFriendParams &paramObj)
	{
		params[0] >> paramObj.returnvalue;
		params[1] << paramObj.userID;
		params[2] << paramObj.friendID;
	}
};