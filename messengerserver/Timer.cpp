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
	StartTime = boost::chrono::system_clock::now();
}


void CTimer::endTimer(void)
{
	EndTime = boost::chrono::system_clock::now();
	mill = boost::chrono::duration_cast<boost::chrono::milliseconds>(EndTime - StartTime);
	std::cout << "걸린 시간 : " << mill.count() << " milliseconds" << std::endl;
	StartTime = EndTime;
}
