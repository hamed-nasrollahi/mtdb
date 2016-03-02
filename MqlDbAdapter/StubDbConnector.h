#pragma once

#include "DbConnector.h"

namespace DB
{
    ref class StubDbConnector : public DbConnector
    {
    public:
        StubDbConnector(System::String^ userName, System::String^ password);
        ~StubDbConnector();

        virtual bool init() override;
        virtual bool writeRecord(System::String^ sqlStr) override;
        virtual bool close() override;

    private:
        System::String^ m_username;
        System::String^ m_password;
    };
}