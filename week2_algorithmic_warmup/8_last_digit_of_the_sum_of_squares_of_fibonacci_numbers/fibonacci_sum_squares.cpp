#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fibonacci_sum_squares_naive()
{
    ll n;
    scanf("%lld", &n);
    if (n == 0 || n == 1)
    {
        printf("%lld", n);
        return;
    }
    int a[120] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6, 1, 8, 0, 9, 0, 0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6, 1, 8, 0, 9, 0};
    int calc1 = a[n % 120] - a[(n - 1) % 120];
    calc1 = calc1 < 0 ? calc1 + 10 : calc1; // get F(n)
    int calc2 = a[(n + 1) % 120] - a[n % 120];
    calc2 = calc2 < 0 ? calc2 + 10 : calc2; // get F(n+1)
    printf("%d", (calc1 * calc2) % 10);
}

int main()
{
    fibonacci_sum_squares_naive();
    return 0;
}
