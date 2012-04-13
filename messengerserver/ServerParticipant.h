#pragma once
class CServerParticipant
{
public:
	virtual ~CServerParticipant() {};
};

typedef boost::shared_ptr<CServerParticipant> ServerParticipant_Ptr;