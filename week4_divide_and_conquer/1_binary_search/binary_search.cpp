#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &v, const int &x)
{
  int low = 0, high = v.size() - 1;
  while (low <= high)
  {
    int mid = ((long long)low + high) / 2;
    if (v[mid] == x)
      return mid;
    if (v[mid] > x)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

void solve()
{
  int n, k, x;
  vector<int> v1, v2;
  scanf("%d", &n);
  for (size_t i = 0; i < n; ++i)
  {
    scanf("%d", &x);
    v1.push_back(x);
  }
  scanf("%d", &k);
  for (size_t i = 0; i < k; ++i)
  {
    scanf("%d", &x);
    printf("%d ", binary_search(v1, x));
  }
}

int main()
{
  solve();
  return 0;
}
