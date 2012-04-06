
void testuserInfo(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tcout << "userid : " << dbmanager.getUserInfo(L"test@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test1@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test3@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test4@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test5@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test10@test.com",L"1234").userID <<std::endl;
	if(-1 == dbmanager.getUserInfo(L"test10@test.com",L"1234").userID)
		tcout << "없는 유저입니다." << endl;
}

void testUserLogState(CDBManager &dbmanager)
{
	CUserInfo user = dbmanager.getUserInfo(L"test@test.com",L"1234");
	CTimer timer;
	timer.startTimer();
	tcout << "userid : " << user.userID << ", login state : " << dbmanager.userLogin(user.userID) << endl;
	timer.endTimer();
	tcout << "userid : " << user.userID << ", logout state : " << dbmanager.userLogout(user.userID) << endl;
	timer.endTimer();
}

void testUserFriends(CDBManager &dbmanager)
{
	userinfos_ptr friends = dbmanager.userFriends(1);

	CTimer timer;
	timer.startTimer();
	cout << "user " << 1 << " friends" << endl;
	std::for_each(friends->begin(),friends->end(),[=](userInfo_ptr userinfo)
	{
		tcout << userinfo->userID << L" " << userinfo->loginID << L" " << userinfo->pw << L" " << userinfo->userName  << endl;
	});

	timer.endTimer();
}

void testUserFriendsLoginState(CDBManager &dbmanager)
{
	userinfos_ptr friends = dbmanager.userFriends(1);
	CTimer timer;
	timer.startTimer();
	tcout << "user " << 1 << " friends" << endl;
	std::for_each(friends->begin(),friends->end(),[=,&dbmanager](userInfo_ptr userinfo)
	{
		bool loginstate = dbmanager.isUserLogin(userinfo->userID);
		tcout << userinfo->userID << "login state : " << loginstate << endl;
	});
	timer.endTimer();

}

void testCreatechattingRoom(CDBManager &dbmanager)
{
	int testUserID = 1;
	FuctionTimer timer;
	
	userinfos_ptr friends = dbmanager.userFriends(testUserID);
	vector<int> friendsIDs;
	std::for_each(friends->begin(),friends->end(),[=,&friendsIDs](userInfo_ptr userinfo)
	{
		friendsIDs.push_back(userinfo->userID);
	});
	
	int chattingroomnumber = dbmanager.makeChattingRoom(testUserID,friendsIDs);
	tcout<< "채팅방 번호 :" << chattingroomnumber << endl;

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

void testRegistNewUser(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test";
	tstring testUserName;

	if(dbmanager.registerNewUser(testUserLoginID,testUserLoginPw,testUserName))
	{
		tcout << "등록 실패" << endl;
	}
	else
		tcout << "등록 성공" << endl;
}

void testisValidUser(CDBManager &dbmanater)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test100@test.com";
	if(dbmanater.isValidUser(testUserLoginID))
		tcout << "있음" << endl;
	else
		tcout << "없음" << endl;
}

void testChageUserInfo(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test1";
	tstring testUserName = L"test1";
	if(dbmanager.changeUserInfo(testUserLoginID,testUserLoginPw,testUserName))
		tcout << "바뀜" << endl;
	else
		tcout << "안바뀜" << endl;
}

void testUserWithdraw(CDBManager &dbmanager)
{
	FuctionTimer timer;

	tstring testUserLoginID = L"test113@test.com";
	tstring testUserLoginPw = L"test1";
	if (dbmanager.withdrawUser(testUserLoginID,testUserLoginPw))
		tcout << "탈퇴 성공" << endl;
	else
		tcout << "탈퇴 실패" << endl;
}

void testAddfriend(CDBManager &dbmanager)
{
	FuctionTimer timer;
	int testuserID = 1;
	int friendID = 14;

	if (dbmanager.addFriendRequest(testuserID,friendID))
		tcout << "친구 추가 요청 성공" << endl;
	else
		tcout << "친구 추가 요청 실패" << endl;

	std::vector<int> friendRequsts;
	int myusrID = friendID;
	if (dbmanager.didFriendsRequest(myusrID,friendRequsts))
	{
		std::for_each(friendRequsts.begin(),friendRequsts.end(),[=,&dbmanager](int friendRequstID)
		{
			tcout << "내 아이뒤 : " << myusrID <<" 친구 추가 요청 아이뒤 : " << friendRequstID << endl;
			if (dbmanager.addFriendRespond(myusrID,friendRequstID,true))
				tcout << "친구 추가 요청 허락 성공" << endl;
			else
				tcout << "친구 추가 요청 허락 실패" << endl;
		});
	}
}

void testfindUserID(CDBManager &dbmanater)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test100@test.com";
	int findUserID = 0;
	if(dbmanater.findUserID(testUserLoginID,findUserID))
		tcout << "찾는 유저 아이디 : " << testUserLoginID << "있음 아이디 : " << findUserID << endl;
	else
		tcout << "찾는 유저 아이디 : " << testUserLoginID << "없음" << endl;
	testUserLoginID = L"test@test.com";
	if(dbmanater.findUserID(testUserLoginID,findUserID))
		tcout << "찾는 유저 아이디 : " << testUserLoginID << "있음 아이디 : " << findUserID << endl;
	else
		tcout << "찾는 유저 아이디 : " << testUserLoginID << "없음" << endl;

}

void testdelFriend(CDBManager &dbmanater)
{
	FuctionTimer timer;
	int testuserID = 1;
	int testFriendID = 14;
	if(dbmanater.delToFriendsWithEachOther(testuserID,testFriendID))
		tcout << "친구 삭제 성공" << endl;
	else
		tcout << "친구 삭제 실패" << endl;
}