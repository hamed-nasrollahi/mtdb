// TestConsole.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace DB;

int main(array<System::String ^> ^args)
{
    MqlDbConnector connector;

	Console::WriteLine(L"Connect to database");
	//String^ host("tcp:jp876y2hhu.database.windows.net,1433");
    String^ host("MYKHAILO,1433");
	String^ database("StockDb");
	String^ userName("UTX\Mykhailo");
	String^ password("MBrit124!");

	connector.init(host, database, userName, password);

	Console::WriteLine(L"Write record to table");
	int id = 5001;//should be unique
	connector.writeRecord(System::String::Format("INSERT INTO Test (Id, Name) \
										VALUES ({0}, '{1}')", 
										id, "line4"));

	// Just print 1 column Names in console, nothing more...
	//Console::WriteLine(L"Read all records from table");
	//connector.readRecords();

	Console::WriteLine(L"Close connection");
	connector.close();
	
	Console::ReadKey();
    return 0;
}
