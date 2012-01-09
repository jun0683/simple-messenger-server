#pragma once

class CDBManager
{
public:
	CDBManager(void);
	~CDBManager(void);
	void dbLogin(void);
	int login(tstring loginID, tstring pw);
};

