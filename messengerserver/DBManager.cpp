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
	DBView<variant_row> view(L"{call insertChattingRoomState(?,?,?)}", ChattingRoomStateBPA());
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
	
	DBView<variant_row> view(L"{call sendChattingMessage(?,?,?)}", ChattingMessageBPA());
	DBView<variant_row>::sql_iterator print_it = view;
	variant_row r(view.GetDataObj());
	r[L"0"] = roomNumber;
	r[L"1"] = UserID;
	r[L"2"] = chattingMessage;
	*print_it = r;
	return true;
}
