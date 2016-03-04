#pragma once

namespace DB
{
    ref class DbConnector abstract
    {
    public:
        virtual bool init() abstract;
        virtual int execute(System::String^ sqlStr) abstract;
        virtual bool close() abstract;
    };
}