#include "StdAfx.h"
#include "UserManager.h"



void CUserManager::joinUser(IUser_Ptr user)
{
	boost::lock_guard<boost::mutex> lock(m_mutex);
	m_users.insert(user);
}


void CUserManager::leaveUser(IUser_Ptr user)
{
	boost::lock_guard<boost::mutex> lock(m_mutex);
	m_users.erase(user);
}

int CUserManager::getCurrentUserCount()
{
	return m_users.size();
}


void CUserManager::leaveUser(int userID)
{
	boost::lock_guard<boost::mutex> lock(m_mutex);
	//auto user = m_users.find(userID)
	//m_users.erase(user);
}