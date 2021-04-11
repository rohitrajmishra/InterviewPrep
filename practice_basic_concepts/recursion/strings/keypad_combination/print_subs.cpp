#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_subs(string input, string output)
{
  // Base
  if (input.length() == 0)
  {
    cout << output << endl;
    return;
  }

  print_subs(input.substr(1), output);
  print_subs(input.substr(1), output + input[0]);

  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string input;
  cin >> input;
  print_subs(input, "");
}