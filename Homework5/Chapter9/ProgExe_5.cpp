#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()  {
  srand(time(NULL));

  int foo[200][200];
  int foo1[200][200];
  int fooResult[200][200];

  int** foo3 = new int*[200];
  int** foo4 = new int*[200];
  int** fooResult2 = new int*[200];

  //init dyanmic arrays
  for(int i = 0; i < 200; i++ ) {
    foo3[i] = new int[200];
    foo4[i] = new int[200];
    fooResult2[i] = new int[200];
  }

  //fill with random numbers
  for(int i = 0; i < 200; i++)  {
    for(int j = 0; j < 200; j++)  {
      foo[i][j] = rand() % 10;
      foo1[i][j] = rand() % 10;
      foo3[i][j] = rand() % 10;
      foo4[i][j] = rand() % 10;
    }
  }

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  int sum = 0;
  for(int i = 0; i < 200; i++)  {
    for(int j = 0; j < 200; j++)  {
      for(int k = 0; k < 200; k++)  {
        sum = sum + (foo[i][k] * foo1[k][j]);
      }
      fooResult[i][j] = sum;
      sum = 0;
    }
  }
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto timeElapsed = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed for static multiplication: " << timeElapsed << endl;

  t1 = high_resolution_clock::now();
  sum = 0;
  for(int i = 0; i < 200; i++)  {
    for(int j = 0; j < 200; j++)  {
      for(int k = 0; k < 200; k++)  {
        sum = sum + (foo3[i][k] * foo4[k][j]);
      }
      fooResult2[i][j] = sum;
      sum = 0;
    }
  }
  t2 = high_resolution_clock::now();
  timeElapsed = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed for dynamic multiplication: " << timeElapsed << endl;

  return 0;

  /*
    Some example output:
    C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>a.exe
    Time elapsed for static multiplication: 49003
    Time elapsed for dynamic multiplication: 30002

    C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>a.exe
    Time elapsed for static multiplication: 46003
    Time elapsed for dynamic multiplication: 29002

    C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>a.exe
    Time elapsed for static multiplication: 46003
    Time elapsed for dynamic multiplication: 31002

    C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>a.exe
    Time elapsed for static multiplication: 38003
    Time elapsed for dynamic multiplication: 30001

    C:\Users\Craig\Desktop\CSE465\Homework5\Chapter9>a.exe
    Time elapsed for static multiplication: 36002
    Time elapsed for dynamic multiplication: 29002

    From the results I think it's safe to say that dynamic is a little quicker
    at matrix multiplication than its static counterpart. However, the time difference is
    actually very small between the two tests (< 10000 microseconds or 1 hundreth
    of a second), and in some cases, the times are almost the same. Because of
    this you could probably argue that there isn't really a difference between the two.

  */
}
