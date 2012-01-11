#pragma once

#include "UserInfo.h"

class CDBManager
{
public:
	CDBManager(void);
	~CDBManager(void);
	
	void			dbLogin(void);
	CUserInfo	getUserInfo(tstring loginID, tstring pw);
	bool			userLogin(int userID);
	bool			userLogout(int userID);
	bool			userLog(int userID,bool state);
	bool			isUserLogin(int userID);
	int			makeChattingRoom(int userID,vector<int> friendIDs);
	bool			inviteChattingRoom(int roomNumber, int invitUserID);
	bool			leaveChattingRoom(int roomNumber, int invitUserID);
	bool			ChattingRoomState(int roomNumber, int UserID,bool state);
	userinfos_ptr	userFriends(int userID);
};

