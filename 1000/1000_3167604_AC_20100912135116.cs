using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a=Console.In.ReadToEnd().Split(new char[]{' ','\n','\r','\t'});
            Console.WriteLine(int.Parse(a[0]) + int.Parse(a[1]));
        }
    }
}
