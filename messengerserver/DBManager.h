#pragma once

#include "UserInfo.h"
//////////////////////////////////////////////////////////////////////////
/// DB Procedure Call ����
/// �̱��� ��ü
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
	// �α���
	bool			userLog(int userID,bool state);

public:
	//////////////////////////////////////////////////////////////////////////
	/// ����
	//////////////////////////////////////////////////////////////////////////

	/// ���� ���� ���
	bool			getUserInfo(tstring loginID, tstring pw,__out CUserInfo &userInfo);
	/// ���� ID ���
	bool			getUserID( tstring &loginID,__out int &userID );
	/// ���� Ȯ��
	bool			isValidUser(tstring &NewUserLoginID);
	/// ���� ���� ����
	bool			changeUserInfo(tstring &userID,tstring &newPassword,tstring &newName);
	/// ���� ���
	bool			registerNewUser(tstring &NewUserLoginID,tstring &NewUserLoginPW, tstring &NewUserName);
	/// ���� Ż��
	bool			withdrawUser( tstring &userLoginID, tstring &userLoginPw );

	//////////////////////////////////////////////////////////////////////////
	/// �α���
	//////////////////////////////////////////////////////////////////////////

	/// �α���
	bool			userLogin(int userID);
	/// �α׾ƿ�
	bool			userLogout(int userID);
	/// �α��� ���� Ȯ��
	bool			isUserLogin(int userID);

	//////////////////////////////////////////////////////////////////////////
	/// ä��
	//////////////////////////////////////////////////////////////////////////

	/// ä�÷� ����
	int				makeChattingRoom(int userID,vector<int> friendIDs);
	/// ä�÷� ����
	bool			inviteChattingRoom(int roomNumber, int invitUserID);
	/// ä�÷� ����
	bool			leaveChattingRoom(int roomNumber, int leaveUserID);
	/// ä�÷� ����
	bool			ChattingRoomState(int roomNumber, int UserID,bool state);
	/// �޽��� ����
	bool			sendChattingMessage(int roomNumber,int UserID,tstring &chattingMessage);

	//////////////////////////////////////////////////////////////////////////
	/// ģ��
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