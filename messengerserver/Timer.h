#pragma once
class CTimer
{
private:
	boost::chrono::system_clock::time_point StartTime;
	boost::chrono::system_clock::time_point EndTime;
	boost::chrono::milliseconds mill;
public:
	CTimer(void);
	~CTimer(void);
	void startTimer(void);
	void endTimer(void);
};

