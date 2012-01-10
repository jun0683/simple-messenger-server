
void testuserInfo(CDBManager &dbmanager)
{
	CTimer timer;
	timer.startTimer();
	std::cout << "userid : " << dbmanager.getUserInfo(L"test@test.com",L"1234").userID <<std::endl;
	std::cout << "userid : " << dbmanager.getUserInfo(L"test1@test.com",L"1234").userID <<std::endl;
	std::cout << "userid : " << dbmanager.getUserInfo(L"test3@test.com",L"1234").userID <<std::endl;
	std::cout << "userid : " << dbmanager.getUserInfo(L"test4@test.com",L"1234").userID <<std::endl;
	std::cout << "userid : " << dbmanager.getUserInfo(L"test5@test.com",L"1234").userID <<std::endl;
	timer.endTimer();
}

void testlogginLog(CDBManager &dbmanager)
{
	CUserInfo user = dbmanager.getUserInfo(L"test@test.com",L"1234");
	CTimer timer;
	timer.startTimer();
	std::cout << "userid : " << user.userID << ", login state : " << dbmanager.userLogin(user.userID) << endl;
	timer.endTimer();
	std::cout << "userid : " << user.userID << ", logout state : " << dbmanager.userLogout(user.userID) << endl;
	timer.endTimer();
}

void testUserFriends(CDBManager &dbmanager)
{
	userinfos_ptr friens = dbmanager.userFriends(1);

	CTimer timer;
	timer.startTimer();
	cout << "user " << 1 << " friends" << endl;
	std::for_each(friens->begin(),friens->end(),[=](userInfo_ptr userinfo)
	{
		wcout << userinfo->userID << L" " << userinfo->loginID << L" " << endl;
	});

	timer.endTimer();
}