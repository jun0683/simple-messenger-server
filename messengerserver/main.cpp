#include "StdAfx.h"
#include "DBManager.h"
#include "Timer.h"
#include "UserInfo.h"
#include "testDBCode.h"



int main(int argc, char* argv[])
{
	try
	{
		CDBManager dbmanager;
		dbmanager.dbLogin();
		testuserInfo(dbmanager);
		testUserLogState(dbmanager);
		testUserFriends(dbmanager);
		testUserFriendsLoginState(dbmanager);
		testCreatechattingRoom(dbmanager);
		testSendChattingMessage(dbmanager);
		testRegistNewUser(dbmanager);
		testisValidUser(dbmanager);
		testChageUserInfo(dbmanager);
		testUserWithdraw(dbmanager);
		testAddfriend(dbmanager);
		testfindUserID(dbmanager);
		testdelFriend(dbmanager);
		
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	return 0;
}