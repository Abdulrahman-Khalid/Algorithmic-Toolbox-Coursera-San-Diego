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
int get_change_btm_up(int amount)
{
  // dp[i]: minimum number of coins with denominations 1, 3, 4
  /* state: i amount */
  // dp[0] = 0 how many coins to make amount of 0
  // dp[1] = 1
  // dp[2] = 2
  // dp[3] = min(dp[3-1], dp[3-3], d[3-4]) + 1; (+1 as I took one coin 1, 3 or 4)
  // substitute 3 with i to get transition function
  // and add condition to make sure i(amount) - coin >=0
  // transition: dp[i] = min(dp[i-1], dp[i-3], dp[i-4]) + 1
  dp[0] = 0;
  for (int i = 1; i <= amount; i++)
  {
    dp[i] = INF;
    for (auto &coin: coins)
      if (i >= coin)
        dp[i] = min(dp[i], dp[i-coin]+1);
  }
  return dp[amount];
}

int get_change_top_down(int amount) {
  if (amount == 0) return 0;
  // if I calculated dp[amount] ealier I return it
  if (dp[amount] != 0) return dp[amount]; 
  dp[amount] = INF;
  for (auto &coin: coins)
    if (amount >= coin)
    dp[amount] = min(dp[amount], get_change_top_down(amount-coin)+1);
  return dp[amount];
}

int main()
{
  int amount;
  scn(amount);
  print(get_change_btm_up(amount));
  return 0;
}
