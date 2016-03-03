using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace TestLibrary
{
    class Program
    {
        #region Dll Import functions
        [DllImport("MqlDbAdapter.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int db_init([MarshalAsAttribute(UnmanagedType.LPWStr)] string connection_str, int db_type);

        [DllImport("MqlDbAdapter.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int db_close(int connection_id);

        [DllImport("MqlDbAdapter.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int db_write(int connection_id,
            [MarshalAsAttribute(UnmanagedType.LPWStr)] string sqlstr);
        #endregion

        private static IntPtr _message = IntPtr.Zero;

        static void Main(string[] args)
        {
            if (!TestStubDb())
            {
                Console.WriteLine("Test StubDb Failed!");
                return;
            }

            bool success = TestMsSql();
            if (!TestMsSql())
            {
                Console.WriteLine("Test MsSql Failed!");
                return;
            }

            Console.WriteLine("Test success");
        }

        private static bool TestStubDb()
        {
            string connStr = "test";

            int connId = db_init(connStr, 0);
            if (connId < 0)
            {
                Console.WriteLine("StubDb: Init error!");
                return false;
            }

            if (db_write(connId, null) < 0)
            {
                Console.WriteLine("StubDb: Write error!");
                return false;
            }

            if (db_close(connId) < 0)
            {
                Console.WriteLine("StubDb: Close error!");
                return false;
            }   

            return true;
        }

        private static bool TestMsSql()
        {
            string connectionString = "Data Source = .\\SQLEXPRESS; Initial Catalog = master; Integrated Security = True";

            int connId = db_init(connectionString, 1);
            if (connId < 0)
            {
                Console.WriteLine("Init error: ");
                return false;
            }

            string sql = string.Format("INSERT INTO Pattern (Symbol, Time) VALUES ('{0}', {1})", "EURUSD", 1);
            if (db_write(connId, sql) == 0)
            {
                Console.WriteLine("Write error: ");
                return false;
            }

            if (db_close(connId) == 0)
            {
                Console.WriteLine("Close error: ");
                return false;
            }

            return true;
        }
    }
}
