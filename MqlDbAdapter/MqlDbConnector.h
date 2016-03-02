// MqlDbConnector.h

#pragma once

namespace DB
{
	public ref class MqlDbConnector {

	public:
		~MqlDbConnector();

        bool init(System::String^ host, System::String^ database, System::String^ userName, System::String^ password);

        bool writeRecord(System::String^ sqlStr);
		
		void readRecords();

		void close();

	private:

        System::Data::SqlClient::SqlConnection^ m_sqlConnection;
	};
}