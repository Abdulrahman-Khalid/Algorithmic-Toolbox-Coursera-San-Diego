#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define scn(x) scanf("%d", &x)
#define print(x) printf("%d", x)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef vector<int> VI;
const int INF = 1e9;

int to;
const int N = 1e6 + 5;
int dp[N];
int primitive_calculator(int curr, int cheat)
{
  if (to == curr)
    return 0;
  if (to < curr)
    return INF;
  if (dp[curr] != 0)
    return dp[curr];
  int m1, m2, m3;
  m1 = m2 = m3 = INF;
  if (cheat <= 10000) // to pass the online judge stack full problem
  {
    m1 = primitive_calculator(curr + 1, cheat + 1) + 1;
    m2 = primitive_calculator(curr * 2, cheat + 1) + 1;
    m3 = primitive_calculator(curr * 3, cheat + 1) + 1;
  }
  return dp[curr] = min(m1, min(m2, m3));
}

auto &s = primitive_calculator;
void path_primitive_calculator(int curr)
{
  if (curr >= to)
    return;
  int c1 = curr + 1, c2 = curr * 2, c3 = curr * 3;
  if (s(curr, 0) == s(c1, 0) + 1)
  {
    printf("%d ", c1);
    path_primitive_calculator(c1);
  }
  else if (s(curr, 0) == s(c2, 0) + 1)
  {
    printf("%d ", c2);
    path_primitive_calculator(c2);
  }
  else if (s(curr, 0) == s(c3, 0) + 1)
  {
    printf("%d ", c3);
    path_primitive_calculator(c3);
  }
}

int main()
{
  scn(to);
  cout << primitive_calculator(1, 0) << '\n';
  printf("1 ");
  path_primitive_calculator(1);
  return 0;
}
