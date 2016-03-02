// TestConsoleW32.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

#include "MqlAdapter.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    MqlAdapter connector;

    cout << "Connect to database" << endl;
	connector.Init();

	cout << "Write record to table" << endl;
    wchar_t query[] = L"INSERT INTO Test (Id, Name) VALUES (5000, 'line456')";
    connector.WriteValue(query);

    cout << "Close connection" << endl;
	connector.Close();
	
	char input;
	cin >> input;
	return 0;
}

