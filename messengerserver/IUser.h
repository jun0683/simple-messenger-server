#pragma once
class IUser
{
public:
	IUser(){};	
	virtual ~IUser() {};
	virtual int getUserID() = 0;
	virtual void setUserID(int userID) = 0;
};

typedef boost::shared_ptr<IUser> IUser_Ptr;