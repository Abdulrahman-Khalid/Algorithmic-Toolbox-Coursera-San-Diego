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

const int N = 1e6 + 5;
int dp[N];
VI coins{1, 3, 4};
int get_change(int n)
{
  if (n == 0)
    return 0;
  if (n < 0)
    return INF;
  if (dp[n] != 0)
    return dp[n];
  int ans = INF;
  for (size_t i = 0; i < coins.size(); ++i)
    dp[n] = ans = min(ans, get_change(n - coins[i]) + 1);
  return ans;
}

int main()
{
  int n;
  scn(n);
  print(get_change(n));
  return 0;
}
