#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

void optimal_points()
{
  struct Segment
  {
    int start, end;
  };
  int n;
  scanf("%d", &n);
  vector<Segment> v;
  {
    int a, b;
    for (int i = 0; i < n; ++i)
    {
      scanf("%d %d", &a, &b);
      v.push_back({a, b});
    }
  }
  sort(v.begin(), v.end(), [](Segment &a, Segment &b) { return a.end < b.end; });
  VI ans;
  while (v.size())
  {
    int p = v[0].end;
    ans.push_back(p);
    v.erase(v.begin());
    int i = 0;
    while (i < v.size())
      if (v[i].start <= p && p <= v[i].end)
        v.erase(v.begin() + i);
      else
        i++;
  }
  printf("%ld\n", ans.size());
  for (auto &e : ans)
    printf("%d ", e);
}

int main()
{
  optimal_points();
  return 0;
}
