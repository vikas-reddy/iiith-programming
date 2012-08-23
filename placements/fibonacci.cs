/*
 * C# Program | Fibonacci Series
 *
 */

using System;

namespace MyConsoleApplication
{
	class MyFirstClass
	{
		static void Main(string[] args)
		{
			/*
			System.Console.WriteLine("Hello World!");
			Console.WriteLine(args[2]);
			*/

			int n=5, temp;
			int a=1, b=1;
			for(int i=0; i<n; i++)
			{
				temp = a;
				a = b;
				b += temp;

				System.Console.WriteLine(a);
			}
			System.Console.WriteLine(b);

			//Console.ReadLine();
			return;
		}
	}
}
