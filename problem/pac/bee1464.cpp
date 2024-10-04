#include <bits/stdc++.h>
using namespace std;
#define MAX 2123

struct point{
  int x, y;
  point(){}
  point(int _x, int _y): x(_x), y(_y){}
};

static bool operator<(point u, point v){
  return (u.x < v.x || (u.x == v.x && u.y < v.y));
}

struct vec{
  int x, y;
  vec(){}
  vec(int _x, int _y): x(_x), y(_y){}
  vec(point u, point v): x(u.x - v.x), y(u.y - v.y){}
};

int dot(vec a, vec b){
  return a.x * b.x + a.y * b.y;
}

int zcross(vec a, vec b){
  return a.x * b.y - a.y * b.x;
}

int n;
int np, ncw, nccw;
point p[MAX], cw[MAX], ccw[MAX];
point pivot;

bool cmp1(point a, point b){
  vec u(pivot, a), v(pivot, b);
  if(zcross(u, v) == 0) return dot(u, u) < dot(v, v);
  return zcross(u, v) > 0;
}

bool cmp2(point a, point b){
  vec u(pivot, a), v(pivot, b);
  if(zcross(u, v) == 0) return dot(u, u) < dot(v, v);
  return zcross(u, v) < 0;
}

void hull(){
  pivot = p[0];
  sort(p+1, p+np, cmp1);
  cw[0] = p[np-1]; cw[1] = p[0]; cw[2] = p[1]; ncw = 3;
  for(int i = 2; i < np; i++){
    while(zcross(vec(cw[ncw-2], cw[ncw-1]), vec(cw[ncw-1], p[i])) < 0) ncw--;
    cw[ncw++] = p[i];
  }
  sort(p+1, p+np, cmp2);
  ccw[0] = p[np-1]; ccw[1] = p[0]; ccw[2] = p[1]; nccw = 3;
  for(int i = 2; i < np; i++){
    while(zcross(vec(ccw[nccw-2], ccw[nccw-1]), vec(ccw[nccw-1], p[i])) > 0) nccw--;
    ccw[nccw++] = p[i];
  }
}

int main(){
  int x, y, ans;
  while(scanf("%d", &n), n){
    set<point> points;
    for(int i = 0; i < n; i++){
      scanf("%d %d", &x, &y);
      points.insert(point(x, y));
    }
    for(ans = 0; !points.empty(); ans++){
      np = 0;
      for(auto &q: points) p[np++] = q;
      hull();
      for(int i = 0; i < ncw; i++) points.erase(cw[i]);
      for(int i = 0; i < nccw; i++) points.erase(ccw[i]);
    }
    printf("%sake this onion to the lab!\n", (ans & 1) ? "T": "Do not t");
  }
  return 0;
}