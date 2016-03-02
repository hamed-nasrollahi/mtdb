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
        [DllImport("MqlDbAdapter.dll")]
        public static extern int db_init();

        [DllImport("MqlDbAdapter.dll")]
        public static extern int db_close();

        [DllImport("MqlDbAdapter.dll")]
        public static extern int db_write();
        #endregion

        private static IntPtr _message = IntPtr.Zero;

        static void Main(string[] args)
        {
            if (db_init() < 0)
            {
                Console.WriteLine("Init error: ");
                return;
            }

            if (db_write() < 0)
            {
                Console.WriteLine("Write error: ");
                return;
            }

            if (db_close() < 0)
            {
                Console.WriteLine("Close error: ");
                return;
            }

            Console.WriteLine("Library test success");
        }
    }
}
