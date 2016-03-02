#include "stdafx.h"

#include <vcclr.h>
#include "StubDbConnector.h"
#include <tchar.h>

DB::StubDbConnector::~StubDbConnector()
{

}

bool DB::StubDbConnector::init()
{
    return true;
}

bool DB::StubDbConnector::writeRecord(System::String^ sqlStr)
{
    return true;
}

bool DB::StubDbConnector::close()
{
    return true;
}

