#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define pb push_back

void get_fibonacci_huge_naive()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (n == 0 || n == 1)
    {
        printf("%lld", n);
        return;
    }
    VI a;
    a.pb(0);
    a.pb(1);
    int i = 2;
    while (i <= n)
    {
        a.pb((a[i - 1] + a[i - 2]) % m);
        if ((a[i] == 0 && a[i - 1] == 1))
            break;
        ++i;
    }
    printf("%d", a[(n % i)]);
}

int main()
{
    get_fibonacci_huge_naive();
    return 0;
}
