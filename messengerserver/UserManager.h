﻿#pragma once

#include "IUser.h"


class CUserManager
{
public:
	void	joinUser(IUser_Ptr user);
	void	leaveUser(IUser_Ptr user);
	void	leaveUser(int userID);
	int		getCurrentUserCount();

private:
	set<IUser_Ptr> m_users;
	boost::mutex m_mutex;
	
};

