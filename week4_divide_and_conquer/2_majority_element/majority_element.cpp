#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define scn(x) scanf("%d", &x)

void get_majority_element()
{
  int n, x, ans = -INF;
  scn(n);
  unordered_map<int, int> m;
  for (size_t i = 0; i < n; ++i)
  {
    scn(x);
    if (m.find(x) != m.end())
      ans = max(ans, ++m[x]);
    else
      m[x] = 1;
  }
  if ((int)(n / 2) < ans)
    printf("%d", 1);
  else
    printf("%d", 0);
}

int main()
{
  get_majority_element();
  return 0;
}
