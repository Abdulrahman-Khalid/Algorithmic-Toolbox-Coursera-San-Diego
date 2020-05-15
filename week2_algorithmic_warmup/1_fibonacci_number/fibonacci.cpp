#include <bits/stdc++.h>
using namespace std;

int fibonacci_fast(int n)
{
    int fib[n + 1];
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci_fast(n));
    return 0;
}
