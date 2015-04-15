using System;
using System.Diagnostics;
using System.Threading;

public class Program  {

  static void method1(ref int[,] arr)  {
    int sum = 0;
    sum = 1 + 1;
  }

  static void method2(int[,] arr)  {
    int sum = 0;
    sum = 1 + 1;
  }

  static void Main(string[] args) {
    Stopwatch stopWatch = new Stopwatch();
    stopWatch.Start();
    int[,] test1 = new int[100, 100];
    for(int i = 0; i < 1000000000; i++)  {
      method1(ref test1);
    }
    stopWatch.Stop();
    Console.WriteLine("Time to pass by reference: ");
    Console.WriteLine(stopWatch.ElapsedMilliseconds);

    stopWatch.Start();
    int[,] test2 = new int[100, 100];
    for(int i = 0; i < 1000000000; i++)  {
      method2(test2);
    }
    stopWatch.Stop();
    Console.WriteLine("Time to pass by value: ");
    Console.WriteLine(stopWatch.ElapsedMilliseconds);
  }
}
