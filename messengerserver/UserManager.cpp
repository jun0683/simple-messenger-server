#include "StdAfx.h"
#include "UserManager.h"



void CUserManager::joinUser(ServerParticipant_Ptr user)
{
	m_users.insert(user);
}


void CUserManager::leaveUser(ServerParticipant_Ptr user)
{
	m_users.erase(user);
}
