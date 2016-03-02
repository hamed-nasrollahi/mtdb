#pragma once

#include <vcclr.h>
#include "MqlDbConnector.h"

class __declspec(dllexport) MqlAdapter
{

private:
	gcroot<DB::MqlDbConnector^> _impl;
	
public:
    MqlAdapter();

	void Init();

    void WriteValue(wchar_t* sqlStr);

	void Close();
};

