#include "stdafx.h"

#include <vcclr.h>
#include "StubDbConnector.h"
#include <tchar.h>

DB::StubDbConnector::StubDbConnector(System::String^ userName, System::String^ password)
    : m_username(userName)
    , m_password(password)
{
}

DB::StubDbConnector::~StubDbConnector()
{

}

bool DB::StubDbConnector::init()
{
    if ("user" == m_username && "test" == m_password)
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
