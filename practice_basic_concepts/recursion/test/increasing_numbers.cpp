#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int checkValid(int num)
{
  // Base case
  if (num == 0)
  {
    return 0;
  }

  int rem = num % 10;
  int newNum = num / 10;

  int lastDigit = checkValid(newNum);
  if (lastDigit == -1 || rem <= lastDigit)
  {
    return -1;
  }
  return rem;
}

void printIncreasingNumbers(int n)
{
  int minN = pow(10, n - 1);
  int maxN = pow(10, n); // we will loop through 10^n -1

  for (int i = minN; i < maxN; i++)
  {
    if (checkValid(i) != -1)
    {
      cout << i << " ";
    }
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;

  printIncreasingNumbers(n);
}
