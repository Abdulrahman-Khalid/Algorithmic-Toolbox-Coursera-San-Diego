#include <bits/stdc++.h>
using namespace std;

struct my_struct
{
  string s, cpy;
};

bool my_sort(my_struct &a, my_struct &b)
{
  if (a.cpy > b.cpy)
    return true;
  if (a.cpy == b.cpy)
    return a.s + b.s > b.s + a.s;
  return false;
}

void largest_number()
{
  int n;
  cin >> n;
  vector<my_struct> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    cin >> a[i].s;
    int l = a[i].s.length();
    a[i].cpy = a[i].s + string(4 - l, a[i].s[0]);
  }
  sort(a.begin(), a.end(), my_sort);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); ++i)
    ret << a[i].s;
  string result;
  ret >> result;
  cout << result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  largest_number();
  return 0;
}
