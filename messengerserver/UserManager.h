#pragma once

#include "IUser.h"


class CUserManager
{
public:
	void joinUser(IUser_Ptr user);
	void leaveUser(IUser_Ptr user);
	int getCurrentUserCount();
private:
	set<IUser_Ptr> m_users;
};

