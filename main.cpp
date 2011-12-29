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
using namespace std;

void TestParmCreate() 
{
	try{
		DBStmt("DROP PROCEDURE TestParm").Execute();
	}
	catch (std::exception e)
	{
		cerr << e.what() << endl;
	}

	DBStmt(
		"CREATE PROCEDURE TestParm " 
		"	@OutParm int OUTPUT "
		"AS "
		"	SELECT STRING_VALUE FROM db_example "
		"	SELECT @OutParm = 66 "
		"	RETURN 99"
		).Execute();

}


//BCA : Bind Column Addresses
class TestParmBCA {
public:
	void operator()(BoundIOs &cols, variant_row &row)
	{
		cols["STRING_VALUE"] == row._string();//컬럼중 STRING_VALUE 바인드
		/*
		  == : SQL_PARAM_INPUT_OUTPUT;
		  << : SQL_PARAM_INPUT;
		  >> : SQL_PARAM_OUTPUT;
		*/
		cols[0] >> row._int(); 
		cols[1] == row._int();

		cols.BindVariantRow(row);
	}
};

// Read the contents of a table and print the resulting rows
void StoredProcReadTestParm() {
	cout << "SQL Server stored procedure test" << endl;

	TestParmCreate() ;
	DBView<variant_row> view("{? = call TestParm(?)}", TestParmBCA());


	// Print out the column names
	cout << "column names" << endl;
	vector<string> colNames = view.GetColNames();
	for (vector<string>::iterator name_it = colNames.begin(); name_it !=colNames.end(); ++name_it)
		cout << (*name_it) << " ";
	cout << endl;

	// Print out all rows and columns from our query
	DBView<variant_row>::sql_iterator print_it = view;

	variant_row r(view.GetDataObj());
	r["0"] = 10;
	r["1"] = 10;

	*print_it = r; // assign parameters to execute

	for (++print_it; print_it != view.end(); ++print_it)
	{
		cout << ((variant_row) *print_it)["STRING_VALUE"] << endl;
	}

	cout << endl;
	cout << "After call to MoreResults(), "
		"SQL-Server gives results in output parameters & return code." << endl;
	print_it.MoreResults();

	r = *print_it;
	cout << "param 0 = " << r["0"] << endl;
	cout << "param 1 = " << r["1"] << endl;

	cout << endl;

}

int main(int argc, char* argv[])
{
	const tstring DSN_str(DNSSTR);
	//DBConnection::GetDefaultConnection();
	DBConnection::GetDefaultConnection().Connect(DSN_str);

	if (DBConnection::GetDefaultConnection().GetDBMSEnum() == DBConnection::DB_SQL_SERVER) 
	{
		StoredProcReadTestParm();
	}

	 DBConnection::GetDefaultConnection().Release();

	return 0;
}