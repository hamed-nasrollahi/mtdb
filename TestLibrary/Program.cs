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
        public static extern int init();        
        #endregion

        private static IntPtr _message = IntPtr.Zero;

        static void Main(string[] args)
        {
            if (init() == 0)
            {
                Console.WriteLine("Init error: " + "MetaTraderApi");
                return;
            }

            Console.WriteLine("Init success");
        }
    }
}
