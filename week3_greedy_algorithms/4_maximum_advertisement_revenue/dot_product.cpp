#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef long long ll;

void max_dot_product()
{
  int n, x;
  scanf("%d", &n);
  VI a, c;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    a.push_back(x);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    c.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  ll sum = 0;
  for (int i = 0; i < n; i++)
    sum += (ll)a[i] * c[i];
  printf("%lld", sum);
}

int main()
{
  max_dot_product();
  return 0;
}
