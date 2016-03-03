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

bool DB::StubDbConnector::writeRecord(System::String^ sqlStr)
{
    return true;
}

bool DB::StubDbConnector::close()
{
    return true;
}
