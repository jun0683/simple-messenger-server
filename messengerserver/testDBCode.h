#include "Timer.h"
#include "DBManager.h"

void dbtest();

//유저
void testuserInfo(CDBManager &dbmanager)
{
	FuctionTimer timer;
	CUserInfo userinfo;

	if(dbmanager.getUserInfo(L"test@test.com",L"1234",userinfo))
		tcout << L"있는 유저입니다 userid : " << userinfo.userID  << endl;
	else
		tcout << L"없는 유저입니다." <<endl;
	
	if(dbmanager.getUserInfo(L"test10@test.com",L"1234",userinfo))
		tcout << "있는 유저입니다 userid : L" << userinfo.userID  << endl;
	else
		tcout << L"없는 유저입니다." <<endl;

	if(dbmanager.getUserInfo(L"test3@test.com",L"1234",userinfo))
		tcout << L"있는 유저입니다 userid : " << userinfo.userID  << endl;
	else
		tcout << L"없는 유저입니다." <<endl;

}

void testUserID(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring loginID;
	int userID;

	loginID = L"test@test.com";
	if(dbmanager.getUserID(loginID,userID))
		tcout << L"loginID : " << loginID << L"는 있는 유저입니다 userid : " << userID  << endl;
	else
		tcout << L"loginID : " << loginID << L"는 없는 유저입니다." <<endl;

	loginID = L"test11@test.com";
	if(dbmanager.getUserID(loginID,userID))
		tcout << L"loginID : " << loginID << L"는 있는 유저입니다 userid : " << userID  << endl;
	else
		tcout << L"loginID : " << loginID << L"는 없는 유저입니다." <<endl;
	
	loginID = L"test3@test.com";
	if(dbmanager.getUserID(loginID,userID))
		tcout << L"loginID : " << loginID << L"는 있는 유저입니다 userid : " << userID  << endl;
	else
		tcout << L"loginID : " << loginID << L"는 없는 유저입니다." <<endl;
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
		tcout << L"등록 실패" << endl;
	}
	else
		tcout << L"등록 성공" << endl;
}

void testUserWithdraw(CDBManager &dbmanager)
{
	FuctionTimer timer;

	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test1";
	if (dbmanager.withdrawUser(testUserLoginID,testUserLoginPw))
		tcout << L"탈퇴 성공" << endl;
	else
		tcout << L"탈퇴 실패" << endl;
}

void testisValidUser(CDBManager &dbmanater)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test100@test.com";
	if(dbmanater.isValidUser(testUserLoginID))
		tcout << L"있음" << endl;
	else
		tcout << L"없음" << endl;
}


void testChageUserInfo(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test1";
	tstring testUserName = L"test1";
	if(dbmanager.changeUserInfo(testUserLoginID,testUserLoginPw,testUserName))
		tcout << L"바뀜" << endl;
	else
		tcout << L"안바뀜" << endl;
}

//로그인
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

//채팅
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
	tcout<< L"채팅방 번호 :" << chattingroomnumber << endl;

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
	tstring chattingmessage = L"반갑습니당";
	dbmanager.sendChattingMessage(roomNumber,testUserID1,chattingmessage);
}

//친구

void testAddfriend(CDBManager &dbmanager)
{
	FuctionTimer timer;
	int testuserID = 1;
	int friendID = 14;

	if (dbmanager.addFriendRequest(testuserID,friendID))
		tcout << L"친구 추가 요청 성공" << endl;
	else
		tcout << L"친구 추가 요청 실패" << endl;

	std::vector<int> friendRequsts;
	int myusrID = friendID;
	if (dbmanager.didFriendsRequest(myusrID,friendRequsts))
	{
		std::for_each(friendRequsts.begin(),friendRequsts.end(),[=,&dbmanager](int friendRequstID)
		{
			tcout << L"내 아이뒤 : " << myusrID << L" 친구 추가 요청 아이뒤 : " << friendRequstID << endl;
			if (dbmanager.addFriendRespond(myusrID,friendRequstID,true))
				tcout << L"친구 추가 요청 허락 성공" << endl;
			else
				tcout << L"친구 추가 요청 허락 실패" << endl;
		});
	}
}

void testfindUserID(CDBManager &dbmanater)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test100@test.com";
	int findUserID = 0;
	if(dbmanater.findUserID(testUserLoginID,findUserID))
		tcout << L"찾는 유저 아이디 : " << testUserLoginID << L"있음 아이디 : " << findUserID << endl;
	else
		tcout << L"찾는 유저 아이디 : " << testUserLoginID << L"없음" << endl;
	testUserLoginID = L"test@test.com";
	if(dbmanater.findUserID(testUserLoginID,findUserID))
		tcout << L"찾는 유저 아이디 : " << testUserLoginID << L"있음 아이디 : " << findUserID << endl;
	else
		tcout << L"찾는 유저 아이디 : " << testUserLoginID << L"없음" << endl;

}

void testdelFriend(CDBManager &dbmanater)
{
	FuctionTimer timer;
	int testuserID = 1;
	int testFriendID = 14;
	if(dbmanater.delToFriendsWithEachOther(testuserID,testFriendID))
		tcout << L"친구 삭제 성공" << endl;
	else
		tcout << L"친구 삭제 실패" << endl;
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
