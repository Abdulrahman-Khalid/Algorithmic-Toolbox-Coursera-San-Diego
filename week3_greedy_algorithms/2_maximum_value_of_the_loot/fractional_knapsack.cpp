#include <bits/stdc++.h>
using namespace std;

void get_optimal_value()
{
  int n, W, val, weight;
  scanf("%d %d", &n, &W);
  double ans = 0;
  vector<pair<double, pair<int, int>>> a;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d %d", &val, &weight);
    a.push_back(make_pair((double)val / weight, make_pair(val, weight)));
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n; ++i)
  {
    W -= a[i].second.second;
    ans += a[i].second.first;
    if (W <= 0)
    {
      if (W < 0)
        ans -= abs(W) * a[i].first;
      break;
    }
  }
  printf("%.4f", ans);
}

int main()
{
  get_optimal_value();
  return 0;
}
