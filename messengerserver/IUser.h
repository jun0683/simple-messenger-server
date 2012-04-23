#pragma once
class IUser
{
public:
	virtual ~IUser() {};
};

typedef boost::shared_ptr<IUser> iUser_Ptr;