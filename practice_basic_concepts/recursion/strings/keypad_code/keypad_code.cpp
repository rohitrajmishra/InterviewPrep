#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int keypad(int num, string output[], const string keyArr[])
{
  // Test keyArr
  // cout << num << ":" << keyArr[num] << endl;

  // Base
  if (num == 0)
  {
    output[0] = "";
    return 1;
  }

  int newNum = num / 10;
  int rem = num % 10;
  int count = keypad(newNum, output, keyArr);

  // add required key to output
  int keyArrSize = keyArr[rem].length();
  // cout << "keyArrSize: " << keyArrSize << endl;
  // Create required copies before adding corresponding alphabets to existing op
  // Otherwise existing op will be replaced, and not be pristine for next copies e.g. a + "", b + "", c + "", so create copy of ""
  for (int i = 0; i < keyArrSize; i++)
  {
    for (int j = 0; j < count; j++)
    {
      output[i * count + j] = output[j];
    }
  }
  // Concat required keypad alphabets
  for (int i = 0; i < keyArrSize; i++)
  {
    // cout << i << ":" << keyArr[rem][i] << endl;
    for (int j = 0; j < count; j++)
    {
      output[i * count + j] = output[i * count + j] + keyArr[rem][i];
    }
  }
  // Update count
  count = count * keyArrSize;
  // cout << "count: " << count << endl;
  return count;
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

  int count = keypad(num, output, keyArr);
  for (int i = 0; i < count && i < 10000; i++)
  {
    cout << output[i] << endl;
  }
}
