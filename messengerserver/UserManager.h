#pragma once

#include "ServerParticipant.h"


class CUserManager
{
public:
	void joinUser(ServerParticipant_Ptr user);
	void leaveUser(ServerParticipant_Ptr user);
private:
	set<ServerParticipant_Ptr> m_users;
};

