
void testuserInfo(CDBManager &dbmanager)
{
	CTimer timer;
	timer.startTimer();
	tcout << "userid : " << dbmanager.getUserInfo(L"test@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test1@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test3@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test4@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test5@test.com",L"1234").userID <<std::endl;
	tcout << "userid : " << dbmanager.getUserInfo(L"test10@test.com",L"1234").userID <<std::endl;
	if(InvalidUser == dbmanager.getUserInfo(L"test10@test.com",L"1234").userID)
		tcout << "없는 유저입니다." << endl;
	timer.endTimer();
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
	cout << "user " << 1 << " friends" << endl;
	std::for_each(friends->begin(),friends->end(),[=,&dbmanager](userInfo_ptr userinfo)
	{
		bool loginstate = dbmanager.isUserLogin(userinfo->userID);
		tcout << userinfo->userID << L"login state : " << loginstate << endl;
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

void testRegistNewUser(CDBManager &dbmanager)
{
	FuctionTimer timer;
	tstring testUserLoginID = L"test1@test.com";
	tstring testUserLoginPw = L"test";
	tstring testUserName;

	if(dbmanager.registerNewUser(testUserLoginID,testUserLoginPw,testUserName))
	{
		tcout << L"성공" << endl;
	}
	else
		tcout << L"실패" << endl;
}

void testChageUserPw(CDBManager &dbmanager)
{

}