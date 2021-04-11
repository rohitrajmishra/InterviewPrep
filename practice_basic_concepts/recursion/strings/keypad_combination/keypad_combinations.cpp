#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void printKeypad(int num, string output, const string keyArr[])
{
  // cout << num << ": " << output << endl;
  // Base
  if (num == 0)
  {
    cout << output << endl;
    return;
  }

  int newNum = num / 10;
  int rem = num % 10;

  // add required key to output
  int keyArrSize = keyArr[rem].length();
  for (int i = 0; i < keyArrSize; i++)
  {
    printKeypad(newNum, keyArr[rem][i] + output, keyArr);
  }

  return;
}

void printKeypad(int num)
{
  const string keyArr[] = {"",
                           "",
                           "abc",
                           "def",
                           "ghi",
                           "jkl",
                           "mno",
                           "pqrs",
                           "tuv",
                           "wxyz"};

  string output = "";
  printKeypad(num, output, keyArr);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // Initialize map
  int num;
  cin >> num;

  string output[10000];
  printKeypad(num);
}
