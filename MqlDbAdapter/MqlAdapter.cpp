#include "stdafx.h"
#include "MqlAdapter.h"
#include "Windows.h"

using namespace std;
using namespace System;
using namespace DB;

void convertFromSystemString(wchar_t* dest, String^ src)
{
    pin_ptr<const wchar_t> wch = PtrToStringChars(src);
    memcpy(dest, wch, wcslen(wch) * sizeof(wchar_t));
    dest[wcslen(wch)] = '\0';
}

String^ convertToSystemString(wchar_t* src)
{
    String^ const str1 = gcnew String(src);
    return str1;
}

MqlAdapter::MqlAdapter()
{
	_impl = gcnew MqlDbConnector;
}

void MqlAdapter::Init()
{
	String^ host("tcp:jp876y2hhu.database.windows.net,1433");
	String^ database("myDb");
	String^ userName("bizleruser@jp876y2hhu");
	String^ password("Password1");
	_impl->init(host, database, userName, password);
}

void MqlAdapter::WriteValue(wchar_t* sqlStr)
{
    String^ sqlConverted = convertToSystemString(sqlStr);
    _impl->writeRecord(sqlConverted);
}

void MqlAdapter::Close(){
	_impl->close();
}

