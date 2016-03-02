#include "stdafx.h"
#include "MqlAdapter.h"
#include "Windows.h"

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
	__declspec(dllexport) int db_init(wchar_t* host, wchar_t* database, wchar_t* username, wchar_t* password, int db_type)
	{
		MqlAdapter::Instance->Init(gcnew String(host), gcnew String(database), gcnew String(username), gcnew String(password), db_type);

		return 0;
	}

	__declspec(dllexport) int db_close(int connection_id)
	{
		return 0;
	}

	__declspec(dllexport) int db_write(int connection_id, wchar_t* sqlstr)
	{
		return 0;
	}
}

MqlAdapter::MqlAdapter()
	: m_nextConnectionId(0)
	, m_connectors(gcnew Dictionary<int, MqlDbConnector^>())
{
}

MqlAdapter::MqlAdapter(const MqlAdapter%) 
{ 
	throw gcnew System::InvalidOperationException("MqlAdapter cannot be copy-constructed"); 
}

int MqlAdapter::Init(String^ host, String^ database, String^ userName, String^ password, int dbType)
{
	int connectionId = -1;
	MqlDbConnector^ connector = gcnew MqlDbConnector;
	bool initialized = connector->init(host, database, userName, password);
	if (initialized)
	{
		connectionId = m_nextConnectionId++;
		m_connectors[connectionId] = connector;
	}
	
	return connectionId;
}

bool MqlAdapter::Write(int connectionId, String^ sqlStr)
{
	bool res = false;
	if (m_connectors.ContainsKey(connectionId))
	{
		MqlDbConnector^ connector = m_connectors[connectionId];
		res = connector->writeRecord(sqlStr);
	}

	return res;
}

bool MqlAdapter::Close(int connectionId)
{
	bool res = false;
	if (m_connectors.ContainsKey(connectionId))
	{
		MqlDbConnector^ connector = m_connectors[connectionId];
		connector->close();
		res = true;
	}
	return res;
}

