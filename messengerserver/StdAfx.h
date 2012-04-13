#include <iostream>
#include <boost/bind.hpp>
#include <boost/chrono.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>


#include "DNSStr.h"

#include <DTL.h>
//#include "MessengerErorrCode.h"

using namespace dtl;
using namespace std;
using boost::asio::ip::tcp;
