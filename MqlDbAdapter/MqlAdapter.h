#pragma once

#include <vcclr.h>
#include "MqlDbConnector.h"

ref class MqlAdapter
{
private:
	MqlAdapter();
	MqlAdapter(const MqlAdapter%);
	static MqlAdapter m_instance;

public:
	static property MqlAdapter^ Instance { MqlAdapter^ get() { return %m_instance; } }
	int Init(System::String^ host, System::String^ database, System::String^ userName, System::String^ password, int dbType);
	bool Write(int connectionId, System::String^ sqlStr);
	bool Close(int connectionId);

private:
	int m_nextConnectionId;
	System::Collections::Generic::Dictionary<int, DB::MqlDbConnector^> m_connectors;
};

