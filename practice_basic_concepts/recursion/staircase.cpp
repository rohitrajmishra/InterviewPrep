/* ************
#Staircase

Send Feedback
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :

Integer N

Output Format :

Integer W

Constraints :

1 <= N <= 30

Sample Input 1 :

4

Sample Output 1 :

7

Sample Input 2 :

5

Sample Output 2 :

13
* *************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int staircase(int n)
{
  // Base
  if (n == 1 || n == 2 || n == 3)
  {
    switch (n)
    {
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 4;
      break;
    default:
      break;
    }
  }

  // Recursive call
  int step1 = staircase(n - 1);
  int step2 = staircase(n - 2);
  int step3 = staircase(n - 3);

  int totalSteps = step1 + step2 + step3;
  return totalSteps;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, output;
  cin >> n;
  output = staircase(n);
  cout << output << endl;
}
