#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

void optimal_summands()
{
  int n;
  scanf("%d", &n);
  int i = 1;
  int sum = 0;
  VI ans;
  while (i + sum != n)
  {
    int check = sum + i + i + 1;
    if (check <= n)
    {
      sum += i;
      ans.push_back(i);
    }
    i++;
  }
  ans.push_back(i);
  printf("%ld\n", ans.size());
  for (auto &e : ans)
    printf("%d ", e);
}

int main()
{
  optimal_summands();
  return 0;
}
