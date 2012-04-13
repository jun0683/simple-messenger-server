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
	DBView<CUserInfo,IDAndPWParams> view(L"{? = call getUserInfo(?,?)}", UserInfoBCA(),L"",UserInfoBPA());
	DBView<CUserInfo, IDAndPWParams>::sql_iterator print_it = view;
	print_it.Params().loginID = loginID;
	print_it.Params().pw = pw;
	*print_it = CUserInfo(); // force the statement to execute
	userInfo = *print_it;
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}


bool CDBManager::getUserID( tstring &loginID,__out int &userID )
{
	DBView<UserIDRow,GetUserIDParams> view(L"{? = call getUserID(?)}", UserIDBCA(),L"",GetUserIDBPA());
	DBView<UserIDRow,GetUserIDParams>::sql_iterator print_it = view;
	print_it.Params().loginID = loginID;
	*print_it = UserIDRow(); // force the statement to execute
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
	DBView<EmptyRow, UserLogParams> view(L"{call insertLog(?,?,?)}", EmptyBCA(),L"",UserLogBPA());
	DBView<EmptyRow, UserLogParams>::sql_iterator print_it = view;
	print_it.Params().userID = userID;
	print_it.Params().logState = state;
	*print_it = EmptyRow();
	print_it.MoreResults();
	return print_it.Params().logResult;
}

userinfos_ptr CDBManager::userFriends(int userID)
{
	DBView<CUserInfo, UserIDParams> view(L"{call friends(?)}", UserInfoBCA(),L"",UserIDBPA());
	DBView<CUserInfo, UserIDParams>::sql_iterator print_it = view;

	print_it.Params().userID = userID;
	*print_it = CUserInfo();

	userinfos_ptr friends (new userInfos);

	for (; print_it != view.end(); ++print_it)

	{
		UserInfo_Ptr user (new CUserInfo(*print_it));
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
	
	DBView<EmptyRow,UserParams> view(L"{? = call registerNewUser(?,?,?)}", EmptyBCA(),L"",UserBPA());
	DBView<EmptyRow,UserParams>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = NewUserLoginID;
	print_it.Params().userloginPW = NewUserLoginPW;
	print_it.Params().userName = NewUserName;
	*print_it = EmptyRow();
	print_it.MoreResults();

	return print_it.Params().returnvalue; 
}

bool CDBManager::isValidUser(tstring &NewUserLoginID)
{
	DBView<EmptyRow,ValidUserParams> view(L"{? = call isValidUser(?)}", EmptyBCA(),L"",ValidUserBPA());
	DBView<EmptyRow,ValidUserParams>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = NewUserLoginID;
	*print_it = EmptyRow();
	print_it.MoreResults();

	return print_it.Params().returnvalue;
}

bool CDBManager::changeUserInfo(tstring &userID,tstring &newPassword,tstring &newName)
{
	DBView<EmptyRow,UserParams> view(L"{? = call changeUserInfo(?,?,?)}", EmptyBCA(),L"",UserBPA());
	DBView<EmptyRow,UserParams>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = userID;
	print_it.Params().userloginPW = newPassword;
	print_it.Params().userName = newName;
	*print_it = EmptyRow();
	print_it.MoreResults();

	return print_it.Params().returnvalue;

}

bool CDBManager::withdrawUser( tstring &userLoginID, tstring &userLoginPw )
{

	DBView<EmptyRow,WithdrawParams> view(L"{? = call withdrawUser(?,?)}", EmptyBCA(),L"",WithdrawBPA());
	DBView<EmptyRow,WithdrawParams>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = userLoginID;
	print_it.Params().userloginPW = userLoginPw;
	*print_it = EmptyRow();
	print_it.MoreResults();

	return print_it.Params().returnvalue;
}

bool CDBManager::addFriendRequest( int userID, int friendID )
{
	DBView<EmptyRow,AddFriendRequestParams> view(L"{? = call addFriendRequest(?,?)}", EmptyBCA(),L"",AddFriendRequestBPA());
	DBView<EmptyRow,AddFriendRequestParams>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyRow();
	tcout << print_it.Params().returnvalue;
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::didFriendsRequest( int friendID, __out std::vector<int> &friendRequsts )
{
	DBView<DidFriendsRequstRow,DidFriendsRequstParams> view(L"{? = call didFriendsRequest(?)}", DidFriendsRequstBCA(),L"",DidFriendsRequstBPA());
	DBView<DidFriendsRequstRow,DidFriendsRequstParams>::sql_iterator print_it = view.begin();
	print_it.Params().friendID = friendID;
	*print_it = DidFriendsRequstRow();
	
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
	DBView<EmptyRow,AddFriendRespondParams> view(L"{? = call updateFriendRequestState(?,?,?)}", EmptyBCA(),L"",AddFriendRespondBPA());
	DBView<EmptyRow,AddFriendRespondParams>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	print_it.Params().respond = respond;
	*print_it = EmptyRow();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::addFriend( int userID, int friendID )
{
	DBView<EmptyRow,AddFriendParams> view(L"{? = call addFriend(?,?)}", EmptyBCA(),L"",AddFriendBPA());
	DBView<EmptyRow,AddFriendParams>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyRow();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::delFriendRequest( int userID, int friendID )
{
	DBView<EmptyRow,DelFriendRequestParams> view(L"{? = call delFriendRequest(?,?)}", EmptyBCA(),L"",DelFriendRequestBPA());
	DBView<EmptyRow,DelFriendRequestParams>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyRow();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::findUserID( tstring &userLoginID,__out int &findUserID )
{
	DBView<FindUserIDRow,FindUserParams> view(L"{? = call findUser(?)}", FindUserIDBCA(),L"",FindUserBPA());
	DBView<FindUserIDRow,FindUserParams>::sql_iterator print_it = view.begin();
	print_it.Params().userloginID = userLoginID;
	*print_it = FindUserIDRow();

	for (; print_it != view.end(); ++print_it)
	{
		findUserID = print_it.GetDataObj().userID;
	}

	print_it.MoreResults();
	return print_it.Params().returnvalue;
}



bool CDBManager::delFriend( int userID, int friendID )
{
	
	DBView<EmptyRow,DelFriendParams> view(L"{? = call delFriend(?,?)}", EmptyBCA(),L"",DelFriendBPA());
	DBView<EmptyRow,DelFriendParams>::sql_iterator print_it = view.begin();
	print_it.Params().userID = userID;
	print_it.Params().friendID = friendID;
	*print_it = EmptyRow();
	print_it.MoreResults();
	return print_it.Params().returnvalue;
}

bool CDBManager::delToFriendsWithEachOther( int userID, int friendID )
{
	return delFriend(userID,friendID) && delFriend(friendID,userID);
}




