#include <bits/stdc++.h>
using namespace std;

template <typename ForwardIterator, typename T>
ForwardIterator first_less_than_or_equal(ForwardIterator first, ForwardIterator last, T val)
{
    auto it = upper_bound(first, last, val);
    return (it == first) ? last : (it - 1);
}

void compute_min_refills()
{
    int d, m, n, x, ans = 0, pos = 0;
    scanf("%d %d %d", &d, &m, &n);
    vector<int> a;
    if (m >= d)
    {
        printf("%d", 0);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        a.push_back(x);
    }
    a.push_back(d);
    int from = 0;
    int i = 0;
    while (i <= n)
    {
        auto it = first_less_than_or_equal(a.begin() + i, a.end(), (m + pos));
        if (it == a.end())
        {
            printf("%d", -1);
            return;
        }
        i = distance(a.begin(), it) + 1;
        pos = *it;
        ans++;
    }
    printf("%d", ans - 1);
}

int main()
{
    compute_min_refills();
    return 0;
}
