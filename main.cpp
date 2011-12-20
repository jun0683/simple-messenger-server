#pragma comment(lib, "DTL.lib")
#pragma comment(lib, "odbc32.lib")
#pragma comment(lib, "odbccp32.lib")

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <dtl.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "DNSStr.h"



using namespace dtl;
//using namespace std;

int main(int argc, char* argv[])
{
	const tstring DSN_str(DNSSTR);
	//DBConnection::GetDefaultConnection();
	DBConnection::GetDefaultConnection().Connect(DSN_str);

	return 0;
}