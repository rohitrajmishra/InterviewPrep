#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(int input[], int si, int ei)
{
  for (int i = si; i <= ei; i++)
  {
    cout << input[i] << " ";
  }
  cout << endl;
}

int partition(int a[], int si, int ei)
{
  // Lets assume first element as pivot
  int pivot = a[si];
  int cSmall = 0;
  for (int i = si + 1; i <= ei; i++)
  {
    if (a[i] < pivot)
    {
      cSmall++;
    }
  }

  // Send pivot at corret index( cSmall, [c], bigger or equal elements)
  int c = cSmall + si;
  int temp = a[c];
  a[c] = pivot;
  a[si] = temp;

  /* send all smaller elements to left
  and equal or bigger elements to right*/
  int i = si;
  int j = ei;

  while (i < c && j > c)
  {
    if (a[i] < a[c])
    {
      i++;
    }
    else if (a[j] >= a[c])
    {
      j--;
    }
    else
    {
      // Swap if both side has elements in wrong order
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  return c;
}

void quickSort(int input[], int si, int ei)
{
  // Base case
  if (si >= ei)
  {
    return;
  }

  int c = partition(input, si, ei);
  // display(input, si, ei);
  quickSort(input, si, c - 1);
  quickSort(input, c + 1, ei);
}

void quickSort(int input[], int size)
{
  quickSort(input, 0, size - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  int *input = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
  }

  quickSort(input, n);
  for (int i = 0; i < n; i++)
  {
    cout << input[i] << " ";
  }

  delete[] input;
}
