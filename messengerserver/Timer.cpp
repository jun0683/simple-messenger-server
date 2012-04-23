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
	tcout << L"�Լ� ����" << endl;
	StartTime = boost::chrono::system_clock::now();
}


void CTimer::endTimer(void)
{
	EndTime = boost::chrono::system_clock::now();
	mill = boost::chrono::duration_cast<boost::chrono::milliseconds>(EndTime - StartTime);
	tcout << L"�ɸ� �ð� : " << mill.count() << L" milliseconds" << endl;
	StartTime = EndTime;
}
