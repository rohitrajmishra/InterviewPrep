#include <iostream>
#include <cmath>
using namespace std;

int subs(string input, string output[])
{
  int smallOutSize = 0;
  // Base
  if (input.size() == 0)
  {
    output[0] = "";
    return 1;
  }

  smallOutSize = subs(input.substr(1), output);
  for (int i = 0; i < smallOutSize; i++)
  {
    output[i + smallOutSize] = input[0] + output[i];
  }

  return 2 * smallOutSize;
}

int main()
{
  string input;
  cout << "Enter string: ";
  cin >> input;
  double outSize = pow(2, input.size());
  // int outSize;
  cout << "outSize: " << outSize << endl;
  string *output = new string[1000];

  outSize = subs(input, output);

  // Display output
  for (int i = 0; i < outSize; i++)
  {
    cout << output[i] << endl;
  }

  // delete output array
  delete[] output;
}