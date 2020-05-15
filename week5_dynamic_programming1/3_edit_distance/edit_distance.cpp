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

string str1, str2;
int dp[101][101];
int edit_distance(int i, int j)
{
  if (i == 0)
    return j;
  if (j == 0)
    return i;
  if (dp[i][j] != 0)
    return dp[i][j];
  int m3 = INF;
  if (str1[i - 1] == str2[j - 1])
    return dp[i][j] = edit_distance(i - 1, j - 1);
  else
    m3 = edit_distance(i - 1, j - 1);
  int m1 = edit_distance(i - 1, j);
  int m2 = edit_distance(i, j - 1);
  return dp[i][j] = min(m1, min(m2, m3)) + 1;
}

int edit_distance_btm_up()
{
  int n1 = str1.length(), n2 = str2.length();
  for (size_t i = 0; i <= n1; ++i)
    dp[i][0] = i;
  for (size_t j = 0; j <= n2; ++j)
    dp[0][j] = j;
  for (size_t i = 1; i <= n1; ++i)
    for (int j = 1; j <= n2; ++j)
    {
      int m1 = dp[i - 1][j] + 1;
      int m2 = dp[i][j - 1] + 1;
      int m3;
      if (str1[i - 1] == str2[j - 1])
        m3 = dp[i - 1][j - 1];
      else
        m3 = dp[i - 1][j - 1] + 1;
      dp[i][j] = min(m1, min(m2, m3));
    }
  return dp[n1][n2];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str1, str2;
  cin >> str1 >> str2;
  cout << edit_distance_btm_up(str1, str2);
  return 0;
}
