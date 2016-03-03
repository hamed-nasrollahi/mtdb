#include "stdafx.h"

#include <vcclr.h>
#include "StubDbConnector.h"
#include <tchar.h>

DB::StubDbConnector::StubDbConnector(System::String^ connectionString)
    : m_connectionString(connectionString)
{
}

DB::StubDbConnector::~StubDbConnector()
{

}

bool DB::StubDbConnector::init()
{
    if ("test" == m_connectionString)
    {
        return true;
    }
    return false;
}

int DB::StubDbConnector::execute(System::String^ sqlStr)
{
    return 0;
}

bool DB::StubDbConnector::close()
{
    return true;
}
