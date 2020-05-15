#include <bits/stdc++.h>
using namespace std;

int MaxPairwiseProduct(const std::vector<int> &numbers)
{
    int max_product = 0;
    int n = numbers.size();
    for (int first = 0; first < n; ++first)
        for (int second = first + 1; second < n; ++second)
            max_product = std::max(max_product, numbers[first] * numbers[second]);
    return max_product;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
    printf("%d", MaxPairwiseProduct(numbers));
    return 0;
}
