#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define dbg(x) cout << #x << " = " << x << ln
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

int maxMoneyLooted(int *arr, int n)
{
  // Boundary check
  if (n == 0)
  {
    return 0;
  }

  int *result = new int[n + 1];
  result[0] = 0;
  result[1] = arr[0];

  for (int i = 2; i < n + 1; i++)
  {
    /* We can choose current or skip it
    * depending on that we can previous one or skip
    */
    // if choose
    int res1 = arr[i - 1] + result[i - 2];
    // if skip
    int res2 = result[i - 1];

    result[i] = max(res1, res2);
  }

  return result[n];
}

int main()
{
  fast_cin();
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << maxMoneyLooted(arr, n);

  delete[] arr;
  return 0;
}