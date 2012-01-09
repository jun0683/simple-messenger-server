#include "StdAfx.h"
#include "DBManager.h"
#include "Timer.h"



int main(int argc, char* argv[])
{
	try
	{
		CDBManager dbmanager;
		dbmanager.dbLogin();
		CTimer timer;
		timer.startTimer();
		std::cout << "userid : " << dbmanager.login(L"test@test.com",L"1234") <<std::endl;
		std::cout << "userid : " << dbmanager.login(L"test1@test.com",L"1234") <<std::endl;
		std::cout << "userid : " << dbmanager.login(L"test3@test.com",L"1234") <<std::endl;
		std::cout << "userid : " << dbmanager.login(L"test4@test.com",L"1234") <<std::endl;
		std::cout << "userid : " << dbmanager.login(L"test5@test.com",L"1234") <<std::endl;
		timer.endTimer();
	}
	catch(std::exception e)
	{
		std::cerr << e.what() << endl;
	}
	
	return 0;
}