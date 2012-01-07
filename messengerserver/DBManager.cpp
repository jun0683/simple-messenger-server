#include "DBManager.h"
#include "DNSStr.h"
#include "dtlexam.h"
#include <DTL.h>
#include <boost/chrono.hpp>

using namespace dtl;
using namespace std;


void TestParmCreate() 
{
	try{
		DBStmt(L"DROP PROCEDURE TestParm").Execute();
	}
	catch (std::exception e)
	{
		cerr << e.what() << endl;
	}

	DBStmt(
		L"CREATE PROCEDURE TestParm " 
		L"	@OutParm int OUTPUT "
		L"AS "
		L"	SELECT STRING_VALUE FROM db_example "
		L"	SELECT @OutParm = 66 "
		L"	RETURN 99"
		).Execute();

}


//BCA : Bind Column Addresses
class TestParmBCA {
public:
	void operator()(BoundIOs &cols, variant_row &row)
	{
		cols[_T("STRING_VALUE")] == row._string();//컬럼중 STRING_VALUE 바인드
		/*
		  == : SQL_PARAM_INPUT_OUTPUT;
		  << : SQL_PARAM_INPUT;
		  >> : SQL_PARAM_OUTPUT;
		*/
		cols[0] >> row._int();//아웃풋값
		cols[1] == row._int();//리턴값

		cols.BindVariantRow(row);
	}
};

// Read the contents of a table and print the resulting rows
void StoredProcReadTestParm() {
	wcout << L"SQL Server stored procedure test" << endl;

	TestParmCreate() ;
	DBView<variant_row> view(L"{? = call TestParm(?)}", TestParmBCA());


	// Print out the column names
	wcout << L"column names" << endl;
	vector<dtl::tstring> colNames = view.GetColNames();
	for (vector<dtl::tstring>::iterator name_it = colNames.begin(); name_it !=colNames.end(); ++name_it)
		wcout << *name_it << L" ";
	wcout << endl;

	// Print out all rows and columns from our query
	DBView<variant_row>::sql_iterator print_it = view;

	variant_row r(view.GetDataObj());
	r[_T("0")] = 10;
	r[_T("1")] = 10;

	*print_it = r; // assign parameters to execute

	for (++print_it; print_it != view.end(); ++print_it)
	{
		wcout << ((variant_row) *print_it)[_T("STRING_VALUE")] << endl;
	}

	wcout << endl;
	wcout << L"After call to MoreResults(), "
		L"SQL-Server gives results in output parameters & return code." << endl;
	print_it.MoreResults();

	r = *print_it;
	wcout << L"param 0 = " << r[_T("0")] << endl;
	wcout << L"param 1 = " << r[L"1"] << endl;

	cout << endl;

}

void SharedConnectionRead(const tstring &DSN)
{
	// create new connection
	cout << "Creating new connection and setting it to be the default " 
		<< " to reference it!" << endl;
	DBConnection conn(DSN);
	conn.Connect();

	// make the default connection reference this new connection
	DBConnection::GetDefaultConnection().Share(conn.GetHENV(), conn.GetHDBC());

	// read and print out examples as output
	DBView<Example> view(DBView<Example>::Args().tables(L"DB_EXAMPLE").postfix(exampleOrderBy));

	cout << "Printing out examples from this new default connection!" << endl;

	copy(view.begin(), view.end(), ostream_iterator<Example>(cout, "\n"));

	// as conn destroyed in this example at closing brace,
	// default connection must be released
	// else we'll have a dangling DBConnection object for the default
	DBConnection::GetDefaultConnection().Release();

	// reconnect the default connection under its own power
	// so we won't get surprises in later examples
	DBConnection::GetDefaultConnection().Connect(DSN);
}


CDBManager::CDBManager(void)
{
}


CDBManager::~CDBManager(void)
{

}


void CDBManager::dbLogin(void)
{
	const tstring DSN_str(DNSSTR);
	//DBConnection::GetDefaultConnection();

	DBConnection::GetDefaultConnection().Connect(DSN_str);
	boost::chrono::system_clock::time_point StartTime = boost::chrono::system_clock::now();
	if (DBConnection::GetDefaultConnection().GetDBMSEnum() == DBConnection::DB_SQL_SERVER) 
	{

		StoredProcReadTestParm();
	}
	boost::chrono::system_clock::time_point EndTime = boost::chrono::system_clock::now();
	boost::chrono::duration<double> DefaultSec = EndTime - StartTime;
	boost::chrono::milliseconds mill = boost::chrono::duration_cast<boost::chrono::milliseconds>(EndTime - StartTime);
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << DefaultSec.count() << " default" << std::endl;
	std::cout << "Test() 함수를 수행하는 걸린 시간 : " << mill.count() << " milliseconds" << std::endl;

	SharedConnectionRead(DNSSTR);



	DBConnection::GetDefaultConnection().Release();


}
