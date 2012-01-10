#include "StdAfx.h"
#include "DBManager.h"
#include "Timer.h"
#include "UserInfo.h"


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
	std::cout << "userid : " << user.userID << "login state : " << dbmanager.userLogin(user.userID) << endl;
	timer.endTimer();
	std::cout << "userid : " << user.userID << "logout state : " << dbmanager.userLogout(user.userID) << endl;
	timer.endTimer();
}


int main(int argc, char* argv[])
{
	try
	{
		CDBManager dbmanager;
		dbmanager.dbLogin();
		testuserInfo(dbmanager);
		testlogginLog(dbmanager);
		
	}
	catch(std::exception e)
	{
		std::cerr << e.what() << endl;
	}
	
	return 0;
}