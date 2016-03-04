#pragma once

#include "DbConnector.h"

namespace DB
{
    ref class StubDbConnector : public DbConnector
    {
    public:
        StubDbConnector(System::String^ connectionString);
        ~StubDbConnector();

        virtual bool init() override;
        virtual int execute(System::String^ sqlStr) override;
        virtual bool close() override;

    private:
        System::String^ m_connectionString;
    };
}