#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int l, int m, int r)
{
  int invCount = 0;
  int i, j, k, n1 = m - l + 1, n2 = r - m;

  int L[n1], R[n2];
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++], invCount += (n1 - i);

  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
  return invCount;
}

int mergeSort(vector<int> &arr, int l, int r)
{
  int invCount = 0;
  if (l < r)
  {
    int m = l + (r - l) / 2;
    invCount = mergeSort(arr, l, m);
    invCount += mergeSort(arr, m + 1, r);

    invCount += merge(arr, l, m, r);
  }
  return invCount;
}

void get_number_of_inversions()
{
  int n;
  vector<int> arr(n);
  scanf("%d", &n);
  for (size_t i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  int inversions = mergeSort(arr, 0, n - 1);
  printf("%d", inversions);
}

int main()
{
  get_number_of_inversions();
  return 0;
}
