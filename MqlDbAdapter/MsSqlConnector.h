// MqlDbConnector.h

#pragma once

#include "DbConnector.h"

namespace DB
{
    ref class MsSqlConnector : public DbConnector
    {

	public:
        MsSqlConnector(System::String^ connectionString);
        ~MsSqlConnector();

        virtual bool init() override;
        virtual bool writeRecord(System::String^ sqlStr) override;		
		void readRecords();
        virtual bool close() override;

	private:


        System::Data::SqlClient::SqlConnection^ m_sqlConnection;
	};
}