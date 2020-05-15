#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd_naive(ll a, ll b) { return b ? gcd_naive(b, a % b) : a; }

int main()
{
  ll a, b;
  scanf("%lld %lld", &a, &b);
  printf("%lld", gcd_naive(a, b));
  return 0;
}
