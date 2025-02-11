using System;

namespace HelloWorld
{
    public class Program
        {
	    public static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
             
            Console.WriteLine("{0}", A * 1000 + B * 10000);
        }
    }
}
