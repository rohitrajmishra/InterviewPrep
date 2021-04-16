/*
 Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :

A numeric string

Constraints :
1 <= Length of String S <= 10
Sample Input:

1123

Sample Output:

aabc
kbc
alc
aaw
kw


*/
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// Little hack, just print similar output instead of storing and returning count
void getCodes(string num, string output, const string options[])
{
  // Base
  if (num.length() == 0)
  {
    cout << output << endl;
    return;
  }

  int d1 = int(num[0] - '0');
  getCodes(num.substr(1), output + options[d1], options);
  if (num.length() >= 2)
  {
    int d2 = (d1 * 10) + (int(num[1] - '0'));
    if (d2 >= 10 && d2 <= 26)
    {
      getCodes(num.substr(2), output + options[d2], options);
    }
  }
}

int getCodes(string input, string output[10000])
{
  string options[] = {"",
                      "a",
                      "b",
                      "c",
                      "d",
                      "e",
                      "f",
                      "g",
                      "h",
                      "i",
                      "j",
                      "k",
                      "l",
                      "m",
                      "n",
                      "o",
                      "p",
                      "q",
                      "r",
                      "s",
                      "t",
                      "u",
                      "v",
                      "w",
                      "x",
                      "y",
                      "z"};
  getCodes(input, "", options);
  return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string input;
  cin >> input;

  string output[10000];
  int count = getCodes(input, output);
  for (int i = 0; i < count && i < 10000; i++)
    cout << output[i] << endl;
  return 0;
}
