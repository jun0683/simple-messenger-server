#pragma once

#include "UserInfo.h"

class CDBManager
{
public:
	CDBManager(void);
	~CDBManager(void);
	

	//////////////////////////////////////////////////////////////////////////
	/// 유저
	//////////////////////////////////////////////////////////////////////////
	bool getUserInfo(tstring loginID, tstring pw,__out CUserInfo &userInfo);
	bool			registerNewUser(tstring &NewUserLoginID,tstring &NewUserLoginPW, tstring &NewUserName);
	bool			isValidUser(tstring &NewUserLoginID);
	bool			changeUserInfo(tstring &userID,tstring &newPassword,tstring &newName);
	bool			withdrawUser( tstring &userLoginID, tstring &userLoginPw );
	bool			getUserID( tstring &loginID,__out int &userID );

	//////////////////////////////////////////////////////////////////////////
	/// 로그인
	//////////////////////////////////////////////////////////////////////////
	void			dbLogin(void);
	bool			userLogin(int userID);
	bool			userLogout(int userID);
	bool			userLog(int userID,bool state);
	bool			isUserLogin(int userID);

	//////////////////////////////////////////////////////////////////////////
	/// 채팅
	//////////////////////////////////////////////////////////////////////////
	int				makeChattingRoom(int userID,vector<int> friendIDs);
	bool			inviteChattingRoom(int roomNumber, int invitUserID);
	bool			leaveChattingRoom(int roomNumber, int leaveUserID);
	bool			ChattingRoomState(int roomNumber, int UserID,bool state);
	bool			sendChattingMessage(int roomNumber,int UserID,tstring &chattingMessage);

	//////////////////////////////////////////////////////////////////////////
	/// 친구
	//////////////////////////////////////////////////////////////////////////
	userinfos_ptr	userFriends(int userID);
	bool			addFriendRequest( int userID, int friendID );
	bool			didFriendsRequest( int friendID, __out std::vector<int> &friendRequsts );
	bool			addFriendRespond( int userID, int friendID,bool respond );
	bool			delFriendRequest( int userID, int friendID);
	bool			updateFriendRequestState( int userID, int friendID, bool respond );
	bool			addFriend( int userID, int friendID );
	bool			findUserID( tstring &userLoginID, __out int &findUserID );
	bool			delFriend( int userID, int friendID );
	bool			delToFriendsWithEachOther( int userID, int friendID );
};

