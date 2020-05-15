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
typedef long long ll;
const int INF = 1e9;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
    return a * b;
  else if (op == '+')
    return a + b;
  else if (op == '-')
    return a - b;
  else
    assert(0);
}

string equation;
ll Min[30][30];
ll Max[30][30];
long long get_maximum_value()
{
  int Len = SZ(equation);
  int numOperations = (SZ(equation) + 1) / 2;
  for (int i = 0; i < numOperations; ++i)
    Min[i][i] = stoll(equation.substr(2 * i, 1)), Max[i][i] = stoll(equation.substr(2 * i, 1));
  for (int s = 0; s < numOperations - 1; ++s)
    for (int i = 0; i < numOperations - s - 1; ++i)
    {
      int j = i + s + 1;
      ll minValue = LLONG_MAX, maxValue = LLONG_MIN;
      for (int k = i; k < j; ++k)
      {
        ll a = eval(Min[i][k], Min[k + 1][j], equation[2 * k + 1]);
        ll b = eval(Min[i][k], Max[k + 1][j], equation[2 * k + 1]);
        ll c = eval(Max[i][k], Min[k + 1][j], equation[2 * k + 1]);
        ll d = eval(Max[i][k], Max[k + 1][j], equation[2 * k + 1]);
        minValue = min(minValue, min(a, min(b, min(c, d))));
        maxValue = max(maxValue, max(a, max(b, max(c, d))));
      }
      Min[i][j] = minValue, Max[i][j] = maxValue;
    }
  return Max[0][numOperations - 1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> equation;
  cout << get_maximum_value();
  return 0;
}
