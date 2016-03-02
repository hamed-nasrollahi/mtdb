#pragma once

namespace DB
{
    ref class DbConnector abstract
    {
    public:
        virtual bool init() abstract;
        virtual bool writeRecord(System::String^ sqlStr) abstract;
        virtual bool close() abstract;
    };
}