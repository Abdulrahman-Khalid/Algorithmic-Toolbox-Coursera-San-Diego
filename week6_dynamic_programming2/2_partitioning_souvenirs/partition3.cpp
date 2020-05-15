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

int w, n;
int weights[301];
int dp[10001][301];
int max_amount_gold(int w, int curr)
{
  if (curr >= n)
    return 0;
  if (dp[w][curr] != 0)
    return dp[w][curr];
  int ans = max_amount_gold(w, curr + 1);
  if (weights[curr] <= w)
    ans = max(ans, (max_amount_gold(w - weights[curr], curr + 1) + weights[curr]));
  return dp[w][curr] = ans;
}

void partitioning_souvenirs()
{
  int x;
  scanf("%d", &n);
  int maxElement = -INF;
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &x);
    maxElement = max(maxElement, x);
    weights[i] = x;
    sum += x;
  }
  max_amount_gold(sum, 0);
  max_amount_gold(sum * 2 / 3, 0);
  max_amount_gold(sum / 3, 0);
  if (sum % 3 == 0 && sum / 3 == dp[sum / 3][0] && sum * 2 / 3 == dp[sum * 2 / 3][0] && sum == dp[sum][0])
    printf("%d", 1);
  else
    printf("%d", 0);
}

int main()
{
  partitioning_souvenirs();
  return 0;
}
