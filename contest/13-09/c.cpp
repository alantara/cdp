#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct point{
  ll x, y;
  point(){};
  point(int x, int y): x(x), y(y){};
} point;

int n;
vector<point> c;
point s, d;

ll dist(point p, point q){
  ll dx = abs(p.x - q.x), dy = abs(p.y - q.y);
  return dx * dx + dy * dy;
}

int main(){
  int x, y;
  int t; scanf("%d", &t);
  while(t--){
    c.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d %d", &x, &y);
      c.push_back(point(x, y));
    }
    scanf("%d %d", &x, &y); s = point(x, y);
    scanf("%d %d", &x, &y); d = point(x, y);
    int ans = 1;
    for(auto p: c){
      if(dist(p, d) <= dist(s, d)) ans = 0;
    }
    printf("%s\n", ans ? "YES": "NO");
  }
  return 0;
}