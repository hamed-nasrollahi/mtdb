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
        public static extern int db_init([MarshalAsAttribute(UnmanagedType.LPWStr)] string host,
            [MarshalAsAttribute(UnmanagedType.LPWStr)] string database,
            [MarshalAsAttribute(UnmanagedType.LPWStr)] string username,
            [MarshalAsAttribute(UnmanagedType.LPWStr)] string password, 
            int db_type);

        [DllImport("MqlDbAdapter.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int db_close(int connection_id);

        [DllImport("MqlDbAdapter.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int db_write(int connection_id,
            [MarshalAsAttribute(UnmanagedType.LPWStr)] string sqlstr);
        #endregion

        private static IntPtr _message = IntPtr.Zero;

        static void Main(string[] args)
        {
            bool success = TestStubDb();
            if (success)
            {
                Console.WriteLine("Library test success");
            }
        }

        private static bool TestStubDb()
        {
            string userName = "user";
            string password = "test";

            int connId = db_init(null, null, userName, password, 0);
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
            string host = "tcp:jp876y2hhu.database.windows.net,1433";
            string database = "myDb";
            string userName = "bizleruser@jp876y2hhu";
            string password = "Password1";

            int connId = db_init(host, database, userName, password, 1);
            if (connId < 0)
            {
                Console.WriteLine("Init error: ");
                return false;
            }

            if (db_write(connId, null) < 0)
            {
                Console.WriteLine("Write error: ");
                return false;
            }

            if (db_close(connId) < 0)
            {
                Console.WriteLine("Close error: ");
                return false;
            }

            return true;
        }
    }
}
