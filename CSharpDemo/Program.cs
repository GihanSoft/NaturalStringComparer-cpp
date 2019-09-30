using System;
using System.Runtime.InteropServices;

namespace CSharpDemo
{
    public static class Dll
    {
        [DllImport("NaturalStringComparer.dll")]
        public static extern int Compare(
            [MarshalAs(UnmanagedType.LPStr)]string x,
            [MarshalAs(UnmanagedType.LPStr)]string y);
    }

    class Program
    {
        static void Main(string[] args)
        {
            var x = Dll.Compare("me12x", "me22");
            Console.WriteLine("Hello World!");
        }
    }
}
