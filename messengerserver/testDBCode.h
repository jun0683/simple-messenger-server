#include "Timer.h"
#include "DBManager.h"

void dbtest();

//����
void testuserInfo(CDBManager &dbmanager)
{
	FuctionTimer timer;
	CUserInfo userinfo;

	if(dbmanager.getUserInfo(L"test@test.com",L"1234",userinfo))
		tcout << L"�ִ� �����Դϴ� userid : " << userinfo.userID  << endl;
	else
		tcout << L"���� �����Դϴ�." <<endl;
	
	if(dbmanager.getUserInfo(L"test10@test.com",L"1234",userinfo))
		tcout << "�ִ� �����Դϴ� userid : L" << userinfo.userID  << endl;
	else
		tcout << L"���� �����Դϴ�." <<endl;

	if(dbmanager.getUserInfo(L"test3@test.com",L"1234",userinfo))
		tcout << L"�ִ� �����Դϴ� userid : " << userinfo.userID  << endl;
	else
		tcout << L"���� �����Դϴ�." <<endl;

}

void testUserID(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring loginID;
	int userID;

	loginID = L"test@test.com";
	if(dbmanager.getUserID(loginID,userID))
		tcout << L"loginID : " << loginID << L"�� �ִ� �����Դϴ� userid : " << userID  << endl;
	else
		tcout << L"loginID : " << loginID << L"�� ���� �����Դϴ�." <<endl;

	loginID = L"test11@test.com";
	if(dbmanager.getUserID(loginID,userID))
		tcout << L"loginID : " << loginID << L"�� �ִ� �����Դϴ� userid : " << userID  << endl;
	else
		tcout << L"loginID : " << loginID << L"�� ���� �����Դϴ�." <<endl;
	
	loginID = L"test3@test.com";
	if(dbmanager.getUserID(loginID,userID))
		tcout << L"loginID : " << loginID << L"�� �ִ� �����Դϴ� userid : " << userID  << endl;
	else
		tcout << L"loginID : " << loginID << L"�� ���� �����Դϴ�." <<endl;
}

void testUserLogState(CDBManager &dbmanager)
{
	CUserInfo user;
	dbmanager.getUserInfo(L"test@test.com",L"1234",user);
	CTimer timer;
	timer.startTimer();
	tcout << L"userid : " << user.userID << L", login state : " << dbmanager.userLogin(user.userID) << endl;
	timer.endTimer();
	tcout << L"userid : " << user.userID << L", logout state : " << dbmanager.userLogout(user.userID) << endl;
	timer.endTimer();
}

void testUserFriends(CDBManager &dbmanager)
{
	userinfos_ptr friends = dbmanager.userFriends(1);

	CTimer timer;
	timer.startTimer();
	tcout << L"user " << 1 << L" friends" << endl;
	std::for_each(friends->begin(),friends->end(),[=](UserInfo_Ptr userinfo)
	{
		tcout << userinfo->userID << L" " << userinfo->loginID << L" " << userinfo->pw << L" " << userinfo->userName  << endl;
	});

	timer.endTimer();
}

void testRegistNewUser(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test";
	tstring testUserName;

	if(dbmanager.registerNewUser(testUserLoginID,testUserLoginPw,testUserName))
	{
		tcout << L"��� ����" << endl;
	}
	else
		tcout << L"��� ����" << endl;
}

void testUserWithdraw(CDBManager &dbmanager)
{
	FuctionTimer timer;

	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test1";
	if (dbmanager.withdrawUser(testUserLoginID,testUserLoginPw))
		tcout << L"Ż�� ����" << endl;
	else
		tcout << L"Ż�� ����" << endl;
}

void testisValidUser(CDBManager &dbmanater)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test100@test.com";
	if(dbmanater.isValidUser(testUserLoginID))
		tcout << L"����" << endl;
	else
		tcout << L"����" << endl;
}


void testChageUserInfo(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test1";
	tstring testUserName = L"test1";
	if(dbmanager.changeUserInfo(testUserLoginID,testUserLoginPw,testUserName))
		tcout << L"�ٲ�" << endl;
	else
		tcout << L"�ȹٲ�" << endl;
}

//�α���
void testUserFriendsLoginState(CDBManager &dbmanager)
{
	userinfos_ptr friends = dbmanager.userFriends(1);
	CTimer timer;
	timer.startTimer();
	tcout << L"user " << 1 << L" friends" << endl;
	std::for_each(friends->begin(),friends->end(),[=,&dbmanager](UserInfo_Ptr userinfo)
	{
		bool loginstate = dbmanager.isUserLogin(userinfo->userID);
		tcout << userinfo->userID << L"login state : " << loginstate << endl;
	});
	timer.endTimer();

}

//ä��
void testCreatechattingRoom(CDBManager &dbmanager)
{
	int testUserID = 1;
	FuctionTimer timer;
	
	userinfos_ptr friends = dbmanager.userFriends(testUserID);
	vector<int> friendsIDs;
	std::for_each(friends->begin(),friends->end(),[=,&friendsIDs](UserInfo_Ptr userinfo)
	{
		friendsIDs.push_back(userinfo->userID);
	});
	
	int chattingroomnumber = dbmanager.makeChattingRoom(testUserID,friendsIDs);
	tcout<< L"ä�ù� ��ȣ :" << chattingroomnumber << endl;

	BOOST_FOREACH(int userid,friendsIDs)
	{
		dbmanager.inviteChattingRoom(chattingroomnumber,userid);
		dbmanager.leaveChattingRoom(chattingroomnumber,userid);
	}
}

void testSendChattingMessage(CDBManager &dbmanager)
{
	FuctionTimer timer;
	int testUserID1 = 1,testUserID2 = 6;
	int roomNumber = 1;
	tstring chattingmessage = L"�ݰ����ϴ�";
	dbmanager.sendChattingMessage(roomNumber,testUserID1,chattingmessage);
}

//ģ��

void testAddfriend(CDBManager &dbmanager)
{
	FuctionTimer timer;
	int testuserID = 1;
	int friendID = 14;

	if (dbmanager.addFriendRequest(testuserID,friendID))
		tcout << L"ģ�� �߰� ��û ����" << endl;
	else
		tcout << L"ģ�� �߰� ��û ����" << endl;

	std::vector<int> friendRequsts;
	int myusrID = friendID;
	if (dbmanager.didFriendsRequest(myusrID,friendRequsts))
	{
		std::for_each(friendRequsts.begin(),friendRequsts.end(),[=,&dbmanager](int friendRequstID)
		{
			tcout << L"�� ���̵� : " << myusrID << L" ģ�� �߰� ��û ���̵� : " << friendRequstID << endl;
			if (dbmanager.addFriendRespond(myusrID,friendRequstID,true))
				tcout << L"ģ�� �߰� ��û ��� ����" << endl;
			else
				tcout << L"ģ�� �߰� ��û ��� ����" << endl;
		});
	}
}

void testfindUserID(CDBManager &dbmanater)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test100@test.com";
	int findUserID = 0;
	if(dbmanater.findUserID(testUserLoginID,findUserID))
		tcout << L"ã�� ���� ���̵� : " << testUserLoginID << L"���� ���̵� : " << findUserID << endl;
	else
		tcout << L"ã�� ���� ���̵� : " << testUserLoginID << L"����" << endl;
	testUserLoginID = L"test@test.com";
	if(dbmanater.findUserID(testUserLoginID,findUserID))
		tcout << L"ã�� ���� ���̵� : " << testUserLoginID << L"���� ���̵� : " << findUserID << endl;
	else
		tcout << L"ã�� ���� ���̵� : " << testUserLoginID << L"����" << endl;

}

void testdelFriend(CDBManager &dbmanater)
{
	FuctionTimer timer;
	int testuserID = 1;
	int testFriendID = 14;
	if(dbmanater.delToFriendsWithEachOther(testuserID,testFriendID))
		tcout << L"ģ�� ���� ����" << endl;
	else
		tcout << L"ģ�� ���� ����" << endl;
}

void dbtest()
{
	testuserInfo(*CDBManager::getInstance());
	testUserID(*CDBManager::getInstance());
	testUserLogState(*CDBManager::getInstance());
	testUserFriends(*CDBManager::getInstance());
	testUserFriendsLoginState(*CDBManager::getInstance());
	testCreatechattingRoom(*CDBManager::getInstance());
	testSendChattingMessage(*CDBManager::getInstance());
	testRegistNewUser(*CDBManager::getInstance());
	testisValidUser(*CDBManager::getInstance());
	testChageUserInfo(*CDBManager::getInstance());
	testUserWithdraw(*CDBManager::getInstance());
	testAddfriend(*CDBManager::getInstance());
	testfindUserID(*CDBManager::getInstance());
	testdelFriend(*CDBManager::getInstance());
	CDBManager::Destroyer();
}
