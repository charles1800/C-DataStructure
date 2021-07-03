using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
//using引用包
//namespace类似JAVA的包名。
namespace _7._03
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
            Console.WriteLine(@"abcdefg
hijklnm");
            //使用$语法可以提高代码的可读性，减少代码量。
            int x = 0;
            Console.WriteLine($"{x}");
            //键盘输入
            string name;
            Console.WriteLine("Enter your name");
            name = Console.ReadLine();
            
            Console.WriteLine($"{name}");

        }
    }
}
