#pragma once

#include <vcclr.h>
#include "DbConnector.h"

ref class MqlAdapter
{
private:
	MqlAdapter();
	MqlAdapter(const MqlAdapter%);
	static MqlAdapter m_instance;

public:
	static property MqlAdapter^ Instance { MqlAdapter^ get() { return %m_instance; } }
    int Init(System::String^ connectionString, int dbType);
	int Execute(int connectionId, System::String^ sqlStr);
	bool Close(int connectionId);

private:
	int m_nextConnectionId;
	System::Collections::Generic::Dictionary<int, DB::DbConnector^> m_connectors;
};

