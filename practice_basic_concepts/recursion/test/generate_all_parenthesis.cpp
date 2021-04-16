#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printWellFormedParanthesis(int b1, int b2, string output)
{
  if (b1 == 0 && b2 == 0)
  {
    cout << output << endl;
    return;
  }

  if (b1 != 0)
  {
    printWellFormedParanthesis(b1 - 1, b2, output + '(');
  }
  if (b2 != 0 && b2 > b1)
  {
    printWellFormedParanthesis(b1, b2 - 1, output + ')');
  }

  return;
}

void printWellFormedParanthesis(int n)
{
  if (n == 0)
  {
    return;
  }

  printWellFormedParanthesis(n - 1, n, "(");
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  printWellFormedParanthesis(n);
}
