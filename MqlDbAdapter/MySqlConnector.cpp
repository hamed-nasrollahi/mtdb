#include "stdafx.h"
#include "MySqlConnector.h"

#include <vcclr.h>
#include "Windows.h"
#include <tchar.h>

using namespace System;
using namespace System::Data;
using namespace DB;
using namespace std;
using namespace MySql::Data;

MySqlConnector::MySqlConnector(String^ host, String^ database, String^ userName, String^ password)
{
	m_sqlConnection = gcnew MySqlClient::MySqlConnection(
		String::Format("server={0};port=0;uid={1};pwd={2};database={3};",
                                        host, userName, password, database
                                    ));
}

MySqlConnector::~MySqlConnector()
{
    this->close();
}

bool MySqlConnector::init()
{
    try
    {
        m_sqlConnection->Open(); // Open up the connection
    }
    catch (Exception^ e)
    {
        Console::Write(e->ToString());
        return false;
    }
    __finally
    {
    }

    return true;
}

bool MySqlConnector::writeRecord(String^ sqlStr)
{
    try
    {
        MySqlClient::MySqlCommand^ cmd = gcnew MySqlClient::MySqlCommand();
        cmd->CommandType = Data::CommandType::Text;
        cmd->CommandText = sqlStr;
        cmd->Connection = m_sqlConnection;

        cmd->ExecuteNonQuery();
    }
    catch (Exception^ e)
    {
        Console::Write(e->ToString());
        return false;
    }
    return true;
}

bool MySqlConnector::close()
{
    if (m_sqlConnection->State != ConnectionState::Closed)
    {
        m_sqlConnection->Close();
        return true;
    }

    return false;
}