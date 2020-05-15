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

int dp[101][101];
VI A(101), B(101);
int n, m;

int LCS(int i, int j)
{
  if (i == n || j == m)
    return 0;
  if (dp[i][j] != 0)
    return dp[i][j];
  if (A[i] == B[j])
    return dp[i][j] = LCS(i + 1, j + 1) + 1;
  return dp[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
}

int LCS_btm_up()
{
  for (size_t i = 1; i <= n; i++)
    for (size_t j = 1; j <= m; j++)
    {
      int m = dp[i - 1][j - 1];
      if (A[i - 1] == B[j - 1])
        ++m;
      dp[i][j] = max(m, max(dp[i - 1][j], dp[i][j - 1]));
    }
  return dp[n][m];
}

int main()
{
  scn(n);
  for (int i = 0; i < n; ++i)
    scn(A[i]);
  scn(m);
  for (int i = 0; i < m; ++i)
    scn(B[i]);
  print(LCS_btm_up());
  return 0;
}
