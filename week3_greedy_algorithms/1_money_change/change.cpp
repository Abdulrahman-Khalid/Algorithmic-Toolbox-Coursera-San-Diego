#include <bits/stdc++.h>
using namespace std;

void get_change()
{
  int m;
  scanf("%d", &m);
  int count = m / 10;
  m %= 10;
  count += m / 5 + m % 5;
  printf("%d", count);
}

int main()
{
  get_change();
  return 0;
}
