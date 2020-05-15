#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef vector<int> VI;

void organizing_lottery()
{
  int s, p, x, y;
  scanf("%d %d", &s, &p);
  // in alphabetics (l) < (p) < (r) so we can you chars to represent left, point and right
  vector<pair<int, char>> segPoints; // has both segments and points
  unordered_map<int, int> pointsMap;
  for (size_t i = 0; i < s; ++i)
  {
    scanf("%d %d", &x, &y);
    segPoints.pb(mp(x, 'l')), segPoints.pb(mp(y, 'r'));
  }
  VI points;
  for (size_t i = 0; i < p; ++i)
  {
    scanf("%d", &x);
    points.pb(x);
    segPoints.pb(mp(x, 'p'));
  }
  sort(all(segPoints));
  int countSegments = 0;
  for (size_t i = 0; i < SZ(segPoints); ++i)
  {
    if (segPoints[i].se == 'l')
      ++countSegments;
    else if (segPoints[i].se == 'r')
      --countSegments;
    else
      pointsMap[segPoints[i].fi] = countSegments;
  }
  for (size_t i = 0; i < p; ++i)
    printf("%d ", pointsMap[points[i]]);
}

int main()
{
  organizing_lottery();
  return 0;
}