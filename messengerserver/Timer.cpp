#include "StdAfx.h"
#include "Timer.h"


CTimer::CTimer(void)
{
}


CTimer::~CTimer(void)
{
}


void CTimer::startTimer(void)
{
	tcout << endl;
	tcout << L"함수 시작" << endl;
	StartTime = boost::chrono::system_clock::now();
}


void CTimer::endTimer(void)
{
	EndTime = boost::chrono::system_clock::now();
	mill = boost::chrono::duration_cast<boost::chrono::milliseconds>(EndTime - StartTime);
	tcout << L"걸린 시간 : " << mill.count() << L" milliseconds" << endl;
	StartTime = EndTime;
}
