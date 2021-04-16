/*Flags
Send Feedback
A flag can consists of only three different colors of stripes, White(W), Blue(B) and Red(R). Given an integer N, find and return the number of ways to create such flags having N stripes consisting of these three color stripes only with the following constraints -

1. Stripes of the same color cannot be placed next to each other.
2. A blue stripe must always be placed between a white and a red or between a red and a white one. Hence blue stripe cannot be placed at starting or at ending.
3. Its not necessary to use all three colors.

Input Format :

Single Integer N

Output Format :

Single Integer representing number of ways to create a flag

Constraints :
1 <= N <= 30
Sample Input 1 :

3

Sample Output 1 :

4

Sample Output 1 Explanation :
Possible flags with 3 stripes are : WRW, WBR, RWR, RBW
Sample Input 2 :

4

Sample Output 2 :

6

Sample Output 2 Explanation :
Possible flags with 4 stripes are : WRWR, WRBW, WBRW, RWRW, RWBR, RBWR
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long find_Ways(int n, char p, char pp)
{
  // Base
  if (n == 0)
  {
    return 1;
  }

  int result = 0;
  if (p == 'B' && pp == 'X')
  {
    int c1 = find_Ways(n - 1, 'W', 'B');
    int c2 = find_Ways(n - 1, 'R', 'B');
    result = c1 + c2;
  }
  if (p == 'B' && pp == 'R')
  {
    int c2 = find_Ways(n - 1, 'W', 'R');
    result += c2;
  }
  if (p == 'B' && pp == 'W')
  {
    int c1 = find_Ways(n - 1, 'R', 'B');
    result += c1;
  }

  if (p == 'R')
  {
    if (n >= 2)
    {
      int c1 = find_Ways(n - 1, 'B', 'R');
      result += c1;
    }
    int c2 = find_Ways(n - 1, 'W', 'R');
    result = result + c2;
  }

  if (p == 'W')
  {
    if (n >= 2)
    {
      int c1 = find_Ways(n - 1, 'B', 'W');
      result += c1;
    }

    int c2 = find_Ways(n - 1, 'R', 'W');
    result = result + c2;
  }

  return result;
}

long long find_Ways(int n)
{
  // assume previos is 'B' as first can't be 'B' and prevprev is anything random
  return find_Ways(n, 'B', 'X');
}

// Main
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int N;
  cin >> N;
  cout << find_Ways(N);
}
