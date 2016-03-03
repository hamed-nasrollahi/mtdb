#include "stdafx.h"
#include "MqlAdapter.h"
#include "Windows.h"
#include "StubDbConnector.h"
#include "MsSqlConnector.h"

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace DB;

void convertFromSystemString(wchar_t* dest, String^ src)
{
    pin_ptr<const wchar_t> wch = PtrToStringChars(src);
    memcpy(dest, wch, wcslen(wch) * sizeof(wchar_t));
    dest[wcslen(wch)] = '\0';
}

extern "C" 
{
    __declspec(dllexport) int db_init(wchar_t* connection_str, int db_type)
	{
        return MqlAdapter::Instance->Init(gcnew String(connection_str), db_type);
	}

	__declspec(dllexport) int db_close(int connection_id)
	{
        return MqlAdapter::Instance->Close(connection_id) == true ? 1 : 0;
	}

	__declspec(dllexport) int db_write(int connection_id, wchar_t* sqlstr)
	{
        return MqlAdapter::Instance->Write(connection_id, gcnew String(sqlstr)) == true ? 1 : 0;
	}
}

MqlAdapter::MqlAdapter()
	: m_nextConnectionId(0)
	, m_connectors(gcnew Dictionary<int, DbConnector^>())
{
}

MqlAdapter::MqlAdapter(const MqlAdapter%) 
{ 
	throw gcnew System::InvalidOperationException("MqlAdapter cannot be copy-constructed"); 
}

int MqlAdapter::Init(String^ connectionString, int dbType)
{
	int connectionId = -1;

    DbConnector^ connector = nullptr;
    switch (dbType)
    {
    case 0:
        connector = gcnew StubDbConnector(connectionString);
        break;
    case 1:
        connector = gcnew MsSqlConnector(connectionString);
        break;
    default:
        break;
    }

    if (connector != nullptr)
    {
        bool initialized = connector->init();
        if (initialized)
        {
            connectionId = m_nextConnectionId++;
            m_connectors[connectionId] = connector;
        }
    }
	
	return connectionId;
}

bool MqlAdapter::Write(int connectionId, String^ sqlStr)
{
	bool res = false;
	if (m_connectors.ContainsKey(connectionId))
	{
		DbConnector^ connector = m_connectors[connectionId];
		res = connector->writeRecord(sqlStr);
	}

	return res;
}

bool MqlAdapter::Close(int connectionId)
{
	bool res = false;
	if (m_connectors.ContainsKey(connectionId))
	{
        DbConnector^ connector = m_connectors[connectionId];
		res = connector->close();
	}
	return res;
}

