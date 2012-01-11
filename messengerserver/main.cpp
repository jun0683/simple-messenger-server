#include "StdAfx.h"
#include "DBManager.h"
#include "Timer.h"
#include "UserInfo.h"
#include "testCode.h"



int main(int argc, char* argv[])
{
	try
	{
		CDBManager dbmanager;
		dbmanager.dbLogin();
		testuserInfo(dbmanager);
		testlogginLog(dbmanager);
		testUserFriends(dbmanager);
		testUserFriendsLoginState(dbmanager);
		testCreatechattingRoom(dbmanager);
	}
	catch(std::exception e)
	{
		std::cerr << e.what() << endl;
	}
	
	return 0;
}