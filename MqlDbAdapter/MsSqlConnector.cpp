// This is the main DLL file.

#include "stdafx.h"

#include <vcclr.h>
#include "Windows.h"
#include "MsSqlConnector.h"
#include <tchar.h>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace DB;
using namespace std;


DB::MsSqlConnector::MsSqlConnector(System::String^ connectionString)
{
//    m_sqlConnection = gcnew SqlConnection("Data Source = .\\SQLEXPRESS; Initial Catalog = master; Integrated Security = True");
    m_sqlConnection = gcnew SqlConnection(connectionString);
}

MsSqlConnector::~MsSqlConnector()
{
	this->close();
}

bool MsSqlConnector::init()
{
    try
    {        
		m_sqlConnection->Open(); // Open up the connection
    }
    catch(Exception^ e)
    {
        Console::Write(e->ToString () );
		return false;
    }
    __finally
    {
    }

	return true;
}


// for test
void MsSqlConnector::readRecords()
{
	SqlDataReader^ myReader;
	try{
		SqlCommand^ sqlCommand = gcnew SqlCommand("SELECT Test1 FROM Test", m_sqlConnection);
		myReader = sqlCommand->ExecuteReader();
		while (myReader->Read())
		{
			Console::WriteLine(myReader->GetString(0));
		}
	}
	catch (Exception^ e)
	{
		Console::Write(e->ToString());
	}
	__finally
	{
		myReader->Close();
	}
}

int MsSqlConnector::execute(String^ sqlStr)
{
    int res = -1;

	try
	{
		SqlCommand^ cmd = gcnew SqlCommand();
		cmd->CommandType = Data::CommandType::Text;
		cmd->CommandText = sqlStr;
		cmd->Connection = m_sqlConnection;

        res = cmd->ExecuteNonQuery();
	}
	catch (Exception^ e)
	{
		Console::Write(e->ToString());
		return false;
	}

    return res;
}

bool MsSqlConnector::close()
{
	if (m_sqlConnection->State != ConnectionState::Closed)
    {
		m_sqlConnection->Close();
        return true;
	}

    return false;
}