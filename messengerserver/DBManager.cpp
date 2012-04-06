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

bool CDBManager::getUserInfo( tstring loginID, tstring pw,__out CUserInfo &userInfo )
{
	DBView<CUserInfo,IDAndPWObj> view(L"{? = call getUserInfo(?,?)}", UserInfoBCA(),L"",UserInfoBPA());
	DBView<CUserInfo, IDAndPWObj>::sql_iterator print_it = view;
	print_it.Params().loginID = loginID;
	print_it.Params().pw = pw;
	*print_it = CUserInfo(); // force the statement to execute
	userInfo = *print_it;
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}


bool CDBManager::getUserID( tstring &loginID,__out int &userID )
{
	DBView<UserIDObj,GetUserID> view(L"{? = call getUserID(?)}", UserIDBCA(),L"",GetUserIDBPA());
	DBView<UserIDObj,GetUserID>::sql_iterator print_it = view;
	print_it.Params().loginID = loginID;
	*print_it = UserIDObj(); // force the statement to execute
	userID = print_it->userID;
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}


bool CDBManager::userLogin(int userID)
{
	return userLog(userID,1);
}

bool CDBManager::userLogout(int userID)
{
	return userLog(userID,0);
}

bool CDBManager::isUserLogin(int userID)
{
	DBView<variant_row> view(L"{? = call isUserLogin(?)}", UserLoginStateBCA());
	DBView<variant_row>::sql_iterator print_it = view;
	variant_row r(view.GetDataObj());
	r[L"0"] = -1; //return
	r[L"1"] = userID; // input userid
	*print_it = r;
	print_it.MoreResults();
	r = *print_it;
	return r[L"0"];
}

bool CDBManager::userLog(int userID,bool state)
{
	DBView<EmptyDataObj, ParamUserLog> view(L"{call insertLog(?,?,?)}", EmptyBCA(),L"",UserLogBPA());
	DBView<EmptyDataObj, ParamUserLog>::sql_iterator print_it = view;
	print_it.Params().userID = userID;
	print_it.Params().logState = state;
	*print_it = EmptyDataObj();
	print_it.MoreResults();
	return print_it.Params().logResult;
}

userinfos_ptr CDBManager::userFriends(int userID)
{
	DBView<CUserInfo, ParamUserID> view(L"{call friends(?)}", UserInfoBCA(),L"",UserIDBPA());
	DBView<CUserInfo, ParamUserID>::sql_iterator print_it = view;

	print_it.Params().userID = userID;
	*print_it = CUserInfo();

	userinfos_ptr friends (new userInfos);

	for (; print_it != view.end(); ++print_it)

	{
		userInfo_ptr user (new CUserInfo(*print_it));
		friends->push_back(user);
	}

	return friends;
}

int CDBManager::makeChattingRoom( int userID, vector<int> friendIDs)
{
	DBView<variant_row> view(L"{? = call makeChattingRoom(?)}", ChattingRoomMakeBCA());
	DBView<variant_row>::sql_iterator print_it = view;
	variant_row r(view.GetDataObj());
	r[L"0"] = -1;
	r[L"1"] = userID;
	*print_it = r;
	print_it.MoreResults();
	r = *print_it;
	return r[L"0"];
}

bool CDBManager::inviteChattingRoom( int roomNumber, int inviteUserID )
{
	return ChattingRoomState(roomNumber,inviteUserID,true);;
}

bool CDBManager::leaveChattingRoom( int roomNumber, int leaveUserID )
{

	return ChattingRoomState(roomNumber,leaveUserID,false);
}

bool CDBManager::ChattingRoomState(int roomNumber, int UserID,bool state)
{
	DBView<variant_row> view(L"{call insertChattingRoomState(?,?,?)}", ChattingRoomStateBCA());
	DBView<variant_row>::sql_iterator print_it = view;
	variant_row r(view.GetDataObj());
	r[L"0"] = roomNumber;
	r[L"1"] = UserID;
	r[L"2"] = state;
	*print_it = r;
	return true;
}

bool CDBManager::sendChattingMessage(int roomNumber,int UserID,tstring &chattingMessage)
{
	
	DBView<variant_row> view(L"{call sendChattingMessage(?,?,?)}", ChattingMessageBCA());
	DBView<variant_row>::sql_iterator print_it = view;
	variant_row r(view.GetDataObj());
	r[L"0"] = roomNumber;
	r[L"1"] = UserID;
	r[L"2"] = chattingMessage;
	*print_it = r;
	return true;
}


bool CDBManager::registerNewUser( tstring &NewUserLoginID,tstring &NewUserLoginPW, tstring &NewUserName )
{
	
	DBView<EmptyDataObj,UserObj> view(L"{? = call registerNewUser(?,?,?)}", EmptyBCA(),L"",UserBPA());
	DBView<EmptyDataObj,UserObj>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = NewUserLoginID;
	print_it.Params().userloginPW = NewUserLoginPW;
	print_it.Params().userName = NewUserName;
	*print_it = EmptyDataObj();
	print_it.MoreResults();

	return print_it.Params().returnvalue; 
}

bool CDBManager::isValidUser(tstring &NewUserLoginID)
{
	DBView<EmptyDataObj,ValidUserObj> view(L"{? = call isValidUser(?)}", EmptyBCA(),L"",ValidUserBPA());
	DBView<EmptyDataObj,ValidUserObj>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = NewUserLoginID;
	*print_it = EmptyDataObj();
	print_it.MoreResults();

	return print_it.Params().returnvalue;
}

bool CDBManager::changeUserInfo(tstring &userID,tstring &newPassword,tstring &newName)
{
	DBView<EmptyDataObj,UserObj> view(L"{? = call changeUserInfo(?,?,?)}", EmptyBCA(),L"",UserBPA());
	DBView<EmptyDataObj,UserObj>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = userID;
	print_it.Params().userloginPW = newPassword;
	print_it.Params().userName = newName;
	*print_it = EmptyDataObj();
	print_it.MoreResults();

	return print_it.Params().returnvalue;

}

bool CDBManager::withdrawUser( tstring &userLoginID, tstring &userLoginPw )
{

	DBView<EmptyDataObj,WithdrawObj> view(L"{? = call withdrawUser(?,?)}", EmptyBCA(),L"",WithdrawBPA());
	DBView<EmptyDataObj,WithdrawObj>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = userLoginID;
	print_it.Params().userloginPW = userLoginPw;
	*print_it = EmptyDataObj();
	print_it.MoreResults();

	return print_it.Params().returnvalue;
}

bool CDBManager::addFriendRequest( int userID, int friendID )
{
	DBView<EmptyDataObj,AddFriendRequest> view(L"{? = call addFriendRequest(?,?)}", EmptyBCA(),L"",AddFriendRequestBPA());
	DBView<EmptyDataObj,AddFriendRequest>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyDataObj();
	tcout << print_it.Params().returnvalue;
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::didFriendsRequest( int friendID, __out std::vector<int> &friendRequsts )
{
	DBView<DidFriendsRequst,DidFriendsRequstParamObj> view(L"{? = call didFriendsRequest(?)}", DidFriendsRequstBCA(),L"",DidFriendsRequstBPA());
	DBView<DidFriendsRequst,DidFriendsRequstParamObj>::sql_iterator print_it = view.begin();
	print_it.Params().friendID = friendID;
	*print_it = DidFriendsRequst();
	
	for (; print_it != view.end(); ++print_it)
	{
		friendRequsts.push_back(print_it.GetDataObj().userID);
	}
	print_it.MoreResults();
	return print_it.Params().returnvalue;

}

bool CDBManager::addFriendRespond( int userID, int friendID,bool respond )
{
	if (updateFriendRequestState(friendID,userID,respond))
	{
		if (respond)
		{
			bool addfriend1 = addFriend(friendID,userID);
			bool addfriend2 = addFriend(userID,friendID);
			bool delfriendrequest = delFriendRequest(friendID,userID);
			return addfriend1 && addfriend2 && delfriendrequest;
		}
		return 1;
	}
	return 0;
}

bool CDBManager::updateFriendRequestState( int userID, int friendID, bool respond )
{
	DBView<EmptyDataObj,AddFriendRespond> view(L"{? = call updateFriendRequestState(?,?,?)}", EmptyBCA(),L"",AddFriendRespondBPA());
	DBView<EmptyDataObj,AddFriendRespond>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	print_it.Params().respond = respond;
	*print_it = EmptyDataObj();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::addFriend( int userID, int friendID )
{
	DBView<EmptyDataObj,AddFriend> view(L"{? = call addFriend(?,?)}", EmptyBCA(),L"",AddFriendBPA());
	DBView<EmptyDataObj,AddFriend>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyDataObj();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::delFriendRequest( int userID, int friendID )
{
	DBView<EmptyDataObj,DelFriendRequest> view(L"{? = call delFriendRequest(?,?)}", EmptyBCA(),L"",DelFriendRequestBPA());
	DBView<EmptyDataObj,DelFriendRequest>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyDataObj();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::findUserID( tstring &userLoginID,__out int &findUserID )
{
	DBView<FindUserID,FindUser> view(L"{? = call findUser(?)}", FindUserIDBCA(),L"",FindUserBPA());
	DBView<FindUserID,FindUser>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = userLoginID;
	*print_it = FindUserID();

	for (; print_it != view.end(); ++print_it)
	{
		findUserID = print_it.GetDataObj().userID;
	}

	print_it.MoreResults();
	return print_it.Params().returnvalue;
}



bool CDBManager::delFriend( int userID, int friendID )
{
	
	DBView<EmptyDataObj,DelFriend> view(L"{? = call delFriend(?,?)}", EmptyBCA(),L"",DelFriendBPA());
	DBView<EmptyDataObj,DelFriend>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyDataObj();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::delToFriendsWithEachOther( int userID, int friendID )
{
	return delFriend(userID,friendID) && delFriend(friendID,userID);
}




