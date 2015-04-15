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

    stopWatch.Reset();
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

/*
  C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>ProgExe_6.exe
  Time to pass by reference:
  733
  Time to pass by value:
  730

  C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>ProgExe_6.exe
  Time to pass by reference:
  745
  Time to pass by value:
  731

  C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>ProgExe_6.exe
  Time to pass by reference:
  733
  Time to pass by value:
  735

  As shown above, it looks like pass by refernece and pass by value
  take almost exactly the same amount of time to complete.
*/
