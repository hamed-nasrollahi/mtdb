#pragma once

#include "DbConnector.h"

namespace DB
{
    ref class MySqlConnector : public DbConnector
    {

    public:
        MySqlConnector(System::String^ host, System::String^ database, System::String^ userName, System::String^ password);
        ~MySqlConnector();

        virtual bool init() override;
        virtual bool writeRecord(System::String^ sqlStr) override;
        virtual bool close() override;

    private:

        MySql::Data::MySqlClient::MySqlConnection^ m_sqlConnection;
    };
}