#pragma once

#include "IUser.h"


class CUserManager
{
public:
	void joinUser(iUser_Ptr user);
	void leaveUser(iUser_Ptr user);
private:
	set<iUser_Ptr> m_users;
};
