#include "StdAfx.h"
#include "UserManager.h"



void CUserManager::joinUser(iUser_Ptr user)
{
	m_users.insert(user);
}


void CUserManager::leaveUser(iUser_Ptr user)
{
	m_users.erase(user);
}

int CUserManager::getCurrentUserCount()
{
	return m_users.size();
}
