#include <iostream>
using namespace std;

int getLen(char input[])
{
  int i = 0;
  while (input[i] != '\0')
  {
    i++;
  }
  return i;
}

// void display(char input[], int len)
// {
//   int i = 0;
//   while (input[i] != '\0')
//   {
//     cout << input[i];
//     i++;
//   }
//   cout << endl;
// }

void shiftRightBy2(char input[], int si)
{
  int len = getLen(input);
  // Note: include '\0' also while shifting
  for (int i = len; i >= 0; i--)
  {
    input[i + 2] = input[i];
  }
}

// Change in the given string itself. So no need to return or print anything
void replacePi(char input[])
{
  int len = getLen(input);
  // Base case
  if (len == 0)
  {
    return;
  }

  replacePi(input + 1);
  if (input[0] == 'p')
  {
    if (input[1] == 'i')
    {
      shiftRightBy2(input, 0);
      // place 3.14 in place of pi
      input[0] = '3';
      input[1] = '.';
      input[2] = '1';
      input[3] = '4';
    }
  }
  // display(input, len);
  // shiftRightBy2(input, 0);
  // cout << input << endl;
}

int main()
{
  char input[10000];
  cin.getline(input, 10000);
  replacePi(input);
  cout << input << endl;
}
