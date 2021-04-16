#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void allStringsHelper(char input[], int k, string output)
{
  // Base
  if (k == 0)
  {
    cout << output << endl;
    return;
  }

  for (int i = 0; input[i] != '\0'; i++)
  {
    allStringsHelper(input, k - 1, input[i] + output);
  }

  return;
}

int allStrings(char input[], int k, char output[][100])
{
  allStringsHelper(input, k, "");
  return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  char a[100];
  char b[1000][100];
  cin >> a;
  int k;
  cin >> k;
  int size = allStrings(a, k, b);
  for (int i = 0; i < size; i++)
  {
    cout << b[i] << endl;
  }
}
