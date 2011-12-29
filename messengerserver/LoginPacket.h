#pragma once
#include "packet.h"
class CLoginPacket :
	public CPacket
{
public:
	CLoginPacket(void);
	virtual ~CLoginPacket(void);
};

