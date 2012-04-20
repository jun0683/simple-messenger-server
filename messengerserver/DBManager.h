#pragma once

#include "UserInfo.h"
//////////////////////////////////////////////////////////////////////////
/// DB Procedure Call 해줌
/// 싱글톤 객체
//////////////////////////////////////////////////////////////////////////
class CDBManager
{


	///singleton
private:
	CDBManager(void);
	~CDBManager(void);
	CDBManager(const CDBManager& other){};
	static CDBManager* inst;
public:
	static CDBManager* getInstance() 
	{
		if (inst == 0) 
			inst = new CDBManager();
		return inst;
	}

	static void Destroyer()
	{
		delete inst;
		inst = NULL;
	}

private:
	/// DB Connect
	void			dbLogin(void);
	// 로그인
	bool			userLog(int userID,bool state);

public:
	//////////////////////////////////////////////////////////////////////////
	/// 유저
	//////////////////////////////////////////////////////////////////////////

	/// 유저 정보 얻기
	bool			getUserInfo(tstring loginID, tstring pw,__out CUserInfo &userInfo);
	/// 유저 ID 얻기
	bool			getUserID( tstring &loginID,__out int &userID );
	/// 유저 확인
	bool			isValidUser(tstring &NewUserLoginID);
	/// 유저 정보 변경
	bool			changeUserInfo(tstring &userID,tstring &newPassword,tstring &newName);
	/// 유저 등록
	bool			registerNewUser(tstring &NewUserLoginID,tstring &NewUserLoginPW, tstring &NewUserName);
	/// 유저 탈퇴
	bool			withdrawUser( tstring &userLoginID, tstring &userLoginPw );

	//////////////////////////////////////////////////////////////////////////
	/// 로그인
	//////////////////////////////////////////////////////////////////////////

	/// 로그인
	bool			userLogin(int userID);
	/// 로그아웃
	bool			userLogout(int userID);
	/// 로그인 상태 확인
	bool			isUserLogin(int userID);

	//////////////////////////////////////////////////////////////////////////
	/// 채팅
	//////////////////////////////////////////////////////////////////////////

	/// 채팅룸 만듬
	int				makeChattingRoom(int userID,vector<int> friendIDs);
	/// 채팅룸 입장
	bool			inviteChattingRoom(int roomNumber, int invitUserID);
	/// 채팅룸 퇴장
	bool			leaveChattingRoom(int roomNumber, int leaveUserID);
	/// 채팅룸 상태
	bool			ChattingRoomState(int roomNumber, int UserID,bool state);
	/// 메시지 전송
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

#define DBMgr CDBManager::getInstance() 