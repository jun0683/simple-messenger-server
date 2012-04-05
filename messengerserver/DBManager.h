#pragma once

#include "UserInfo.h"

class CDBManager
{
public:
	CDBManager(void);
	~CDBManager(void);
	
	void			dbLogin(void);
	CUserInfo		getUserInfo(tstring loginID, tstring pw);
	bool			userLogin(int userID);
	bool			userLogout(int userID);
	bool			userLog(int userID,bool state);
	bool			isUserLogin(int userID);
	int				makeChattingRoom(int userID,vector<int> friendIDs);
	bool			inviteChattingRoom(int roomNumber, int invitUserID);
	bool			leaveChattingRoom(int roomNumber, int invitUserID);
	bool			ChattingRoomState(int roomNumber, int UserID,bool state);
	userinfos_ptr	userFriends(int userID);
	bool			sendChattingMessage(int roomNumber,int UserID,tstring &chattingMessage);
	bool			registerNewUser(tstring &NewUserLoginID,tstring &NewUserLoginPW, tstring &NewUserName);
	bool			isValidUser(tstring &NewUserLoginID);
	bool			changeUserInfo(tstring &userID,tstring &newPassword,tstring &newName);
	bool withdrawUser( tstring &userLoginID, tstring &userLoginPw );
	bool addFriendRequest( int userID, int friendID );
	bool didFriendsRequest( int friendID, __out std::vector<int> &friendRequsts );
	bool addFriendRespond( int userID, int friendID,bool respond );
	bool delFriendRequest( int userID, int friendID);
	bool updateFriendRequestState( int userID, int friendID, bool respond );
	bool addFriend( int userID, int friendID );
};

