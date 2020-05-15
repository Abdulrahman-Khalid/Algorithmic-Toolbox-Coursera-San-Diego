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
using std::vector;

VI A(101), B(101), C(101);
int n, m, l;
int dp[101][101][101];
int LCS_3_btm_up()
{
  const int SIZE = 7;
  for (size_t i = 1; i <= n; i++)
    for (size_t j = 1; j <= m; j++)
      for (size_t k = 1; k <= l; k++)
      {
        int m[SIZE];
        m[0] = dp[i - 1][j][k];
        m[1] = dp[i][j - 1][k];
        m[2] = dp[i][j][k - 1];
        m[3] = dp[i - 1][j - 1][k];
        m[4] = dp[i][j - 1][k - 1];
        m[5] = dp[i - 1][j][k - 1];
        m[6] = dp[i - 1][j - 1][k - 1];
        if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
          ++m[6];
        dp[i][j][k] = *max_element(m, m + SIZE);
      }
  return dp[n][m][l];
}

int main()
{
  scn(n);
  for (int i = 0; i < n; ++i)
    scn(A[i]);
  scn(m);
  for (int i = 0; i < m; ++i)
    scn(B[i]);
  scn(l);
  for (int i = 0; i < l; ++i)
    scn(C[i]);
  cout << LCS_3_btm_up();
  return 0;
}
