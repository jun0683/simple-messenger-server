// Example class and other abstractions needed by the example functions

#ifndef _EXAMPLE_CORE_H
#define _EXAMPLE_CORE_H

#include <DTL.h>
#include <iostream>

#ifdef __SGI_STL_PORT
#include <hash_set>
#include <hash_map>
#endif

// #include "vec_multiset.h"

using namespace dtl;
using namespace std;

// order by clause for DB_EXAMPLE to give us more consistent regression test results
const tstring exampleOrderBy = 
	L" ORDER BY INT_VALUE, STRING_VALUE, DOUBLE_VALUE, EXAMPLE_LONG, EXAMPLE_DATE";

// prints out asterisks between each example function
void PrintSeparator(ostream &o);

// prints a header with title for a particular example
void PrintHeader(ostream &o, const string &title);

// Table difference function.
// Takes two containers and prints out the differences (via set difference) between the containers.
// container 1 = "original" values, container 2 = "new" values
// must have same value_type!
template<class Container1, class Container2> 
void TableDiff(ostream &o, const Container1 &cont1, const Container2 &cont2)
{
	typedef typename Container1::value_type value_type;
	// copy container data into sets as set_symmetric_difference needs a sorted list to do its work
	multiset<value_type> set1;
	multiset<value_type> set2;

	// Slight workaround here, M$ compiler 6.0 STL library can only work with pointers not iterators
	// Therefore, cannot do this at set construction time as recommended by the standard
	copy(cont1.begin(), cont1.end(), inserter(set1, set1.begin()));
	copy(cont2.begin(), cont2.end(), inserter(set2, set2.begin()));

	// Show set1 - set2 = deleted / changed items
	o << "deleted / changed items:" << endl;
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
		ostream_iterator<value_type>(o, "\n"));

	// Show set2 - set1 = inserted / changed items
	o << "inserted / changed items:" << endl;
	set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(),
		ostream_iterator<value_type>(o, "\n"));

#if 0
	// Show all differences as single set
	set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
		ostream_iterator<value_type>(o, "\n"));
#endif
}

typedef dtl::tcstring<50> tcstring50_t;

// Define an object to hold our row data -- used by all single table examples
class Example
{
private:                       // tablename.columnname:
	int exampleInt;               // DB_EXAMPLE.INT_VALUE
	string exampleStr;            // DB_EXAMPLE.STRING_VALUE
	double exampleDouble;         // DB_EXAMPLE.DOUBLE_VALUE
	long exampleLong;             // DB_EXAMPLE.EXAMPLE_LONG
	jtime_c exampleDate;          // DB_EXAMPLE.EXAMPLE_DATE

public: 

	Example() : exampleInt(0), exampleStr(""), exampleDouble(0.0),
		exampleLong(0), exampleDate() { }

	Example(int exInt, const string &exStr, double exDouble, 
		long exLong, const TIMESTAMP_STRUCT &exDate) :
	exampleInt(exInt), exampleStr(exStr), exampleDouble(exDouble), 
		exampleLong(exLong), exampleDate(exDate) { }

	// only accessors needed by our examples
	void SetExampleStr(const string &str)
	{
		exampleStr = str;
	}

	string GetExampleStr() const
	{
		return exampleStr;
	}

	jtime_c GetExampleDate() const
	{
		return exampleDate;
	}

	void SetExampleDate(const jtime_c &jtime)
	{
		exampleDate = jtime;
	}

	int GetExampleInt() const {
		return exampleInt;
	}

	long GetExampleLong() const {
		return exampleLong;
	}

	double GetExampleDouble() const {
		return exampleDouble;
	}

	friend class dtl::DefaultBCA<Example>;

	friend class dtl::DefaultInsValidate<Example>;

	friend class ExampleBCA;
	friend class ExampleBPA;

	friend ostream& operator<<(ostream &o, const Example &ex)
	{
		o << "Example(" << ex.exampleInt << ", \"" << ex.exampleStr << "\", ";
		o << ex.exampleDouble << ", " << ex.exampleLong << ", ";
		o << ex.exampleDate << ")" ;

		return o;
	}

	friend bool operator<(const Example &ex1, const Example &ex2)
	{
		if (ex1.exampleInt < ex2.exampleInt)
			return true;
		if (ex1.exampleInt > ex2.exampleInt)
			return false;

		if (ex1.exampleStr < ex2.exampleStr)
			return true;
		if (ex1.exampleStr > ex2.exampleStr)
			return false;

		if (ex1.exampleDouble < ex2.exampleDouble)
			return true;
		if (ex1.exampleDouble > ex2.exampleDouble)
			return false;

		if (ex1.exampleLong < ex2.exampleLong)
			return true;
		if (ex1.exampleLong > ex2.exampleLong)
			return false;

		return (ex1.exampleDate < ex2.exampleDate);
	}


};

// reverse comparison using exampleStr
bool reverse_compare_strings(const Example *pData1, const Example *pData2);

// alternative hashing scheme on exampleStr
size_t my_hash_strings(const Example *pData1);

// Create an association between table columns and fields in our object
// Here, BoundIOs is a class that is passed in to store column names &
// mappings

BEGIN_DTL_NAMESPACE

	template<> class DefaultBCA<Example>
{
public:
	void operator()(BoundIOs &cols, Example &row)
	{
		int & ref = row.exampleInt;
		cols[L"INT_VALUE"]    == (int &)ref;
		cols[L"STRING_VALUE"] == row.exampleStr;
		cols[L"DOUBLE_VALUE"] == row.exampleDouble;
		cols[L"EXAMPLE_LONG"] == row.exampleLong;
		cols[L"EXAMPLE_DATE"] == row.exampleDate;
	}
};

// Specialization of DefaultInsValidate for Example
// This defines a business rule we wish to enforce for all 
// Example objects before they are allowed to be inserted into the database
template<> class DefaultInsValidate<Example>
{
public:

	bool operator()(BoundIOs &cols, Example &rowbuf) {	
		// data is valid if rowbuf.exampleStr is nonempty and
		// rowbuf.exampleDouble is 
		// between 0 and 100 (like a percentage)
		return (rowbuf.exampleStr.length() > 0 &&  rowbuf.exampleDouble >= 0.0 
			&& rowbuf.exampleDouble  <= 100.0);
	}
};
END_DTL_NAMESPACE

class ExampleBCA {
public:
	void operator()(BoundIOs &cols, Example &row)
	{
		cols[0] << row.exampleInt;
		cols[1] << row.exampleStr;
		cols[2] << row.exampleDouble;
		cols[3] << row.exampleLong;
		cols[4] << row.exampleDate;
	}
};

// Parameter object to hold parameters for dynamic SQL query below 
class ParamObjExample
{
public:
	int lowIntValue;
	int highIntValue;
	string strValue;
	TIMESTAMP_STRUCT dateValue;
};

// Create an association between query parameters and fields in our parameters object
class BPAExampleObj
{
public:
	void operator()(BoundIOs &boundIOs, ParamObjExample &paramObj)
	{
		boundIOs[0] == paramObj.lowIntValue;
		boundIOs[1] == paramObj.highIntValue;
		boundIOs[2] == paramObj.dateValue;
		boundIOs[3] == paramObj.strValue;
	}

};

// this function is used to reset the Example table in the database
void ResetTables(DBConnection &connection = DBConnection::GetDefaultConnection());

// define an object to hold our row data -- used for joined table examples
class JoinExample
{
private:                   // tablename.columnname:
	int exampleInt;           // DB_EXAMPLE.INT_VALUE
	string exampleStr;        // DB_EXAMPLE.STRING_VALUE
	double exampleDouble;     // DB_EXAMPLE.DOUBLE_VALUE
	unsigned long sampleLong; // DB_SAMPLE.SAMPLE_LONG
	double extraDouble;       // DB_SAMPLE.EXTRA_FLOAT

public:
	JoinExample() : exampleInt(0), exampleStr(""), exampleDouble(0.0), sampleLong(0),
		extraDouble(0.0) { }

	JoinExample(int exInt, string exStr, double exDouble, unsigned long samLong,
		double extra) : exampleInt(exInt), exampleStr(exStr),
		exampleDouble(exDouble), sampleLong(samLong), extraDouble(extra) { }

	friend class BCAJoinExample;
	friend class BPAJoinParamObj;

	friend ostream& operator<<(ostream &o, const JoinExample &je)
	{
		o << "JoinExample(" << je.exampleInt << ", \"" << je.exampleStr << "\", ";
		o << je.exampleDouble << ", " << je.sampleLong << ", ";
		o << je.extraDouble << ")";
		return o;
	}

	friend bool operator < (const JoinExample &je1, const JoinExample &je2)
	{
		if (je1.exampleInt < je2.exampleInt)
			return true;
		if (je1.exampleInt > je2.exampleInt)
			return false;

		if (je1.exampleStr < je2.exampleStr)
			return true;
		if (je1.exampleStr > je2.exampleStr)
			return false;

		if (je1.exampleDouble < je2.exampleDouble)
			return true;
		if (je1.exampleDouble > je2.exampleDouble)
			return false;

		if (je1.sampleLong < je2.sampleLong)
			return true;
		if (je1.sampleLong > je2.sampleLong)
			return false;

		return (je1.extraDouble < je2.extraDouble);
	}

};

// Here we define a custom parameter object for use with our JoinExample 
class JoinParamObj
{
public:
	int intValue;
	string strValue;
	int sampleInt;
	string sampleStr;
};

// BCA for JoinExample ... needed to store bindings between
// query fields and members in JoinExample objects
class BCAJoinExample
{
public:
	void operator()(BoundIOs &cols, JoinExample &row)
	{
		cols[L"INT_VALUE"]    >> row.exampleInt;
		cols[L"DOUBLE_VALUE"] >> row.exampleDouble;
		cols[L"SAMPLE_LONG"]  >> row.sampleLong;
		cols[L"EXTRA_FLOAT"]  >> row.extraDouble;
		cols[L"STRING_VALUE"] >> row.exampleStr;
	}
};

// BPA for JoinParamObj ... set SQL Query parameters from object
class BPAJoinParamObj
{
public:
	void operator()(BoundIOs &params, JoinParamObj &paramObj)
	{
		params[0] << paramObj.intValue;
		params[1] << paramObj.strValue;
		params[2] << paramObj.sampleInt;
		params[3] << paramObj.sampleStr;

#if 0 // proposed BCA/BPA syntax ... operator<<() and operator>>() call operator==()
		params[0] >> paramObj.intValue; // OUT parameter ... throws on non-sql_iterators (?)
		params[1] << paramObj.strValue; // IN parameter ... throws on non-sql_iterators (?)
		params[2] == paramObj.sampleInt;// INOUT parameter
#endif 
	}
};

// Set parameters function for Example ... used by IndexedDBView<Example> to set dynamic query parameters
// Dynamic query parameters are indicated by (?) in our query string for the IndexedDBView
// we'll use cb_ptr_fun() to wrap this up into a function object that we can pass to
// the IndexedDBView constructor
void SetParamsExample(ParamObjExample &params);

// test out TableDiff() using old and new views
void TestTableDiff();

// Parameter object to hold parameters for dynamic SQL query below 
class ParamsSimpleExample
{
public:
	int lowIntValue;
	int highIntValue;
	string strValue;
	TIMESTAMP_STRUCT dateValue;
};

// Create an association between query parameters and fields in our parameters object
class BPASimpleExampleObj
{
public:
	void operator()(BoundIOs &boundIOs, ParamsSimpleExample &paramObj)
	{
		boundIOs[0] == paramObj.lowIntValue;
		boundIOs[1] == paramObj.highIntValue;
		boundIOs[2] == paramObj.dateValue;
		boundIOs[3] == paramObj.strValue;
	}

};

void SetParamsSimpleExample(ParamsSimpleExample &params);

#endif
