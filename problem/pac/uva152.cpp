#include <bits/stdc++.h>
using namespace std;
#define INF 112345678

struct point{
  int x, y, z;
  point(){}
  point(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
};

int ans[10];
vector<point> points;

int dist(point a, point b){
  int dx = abs(a.x - b.x), dy = abs(a.y - b.y), dz = abs(a.z - b.z);
  return dx * dx + dy * dy + dz * dz;
}

int main(){
  int n, x, y, z;
  for(n = 0; scanf("%d %d %d", &x, &y, &z), x | y | z; n++){
    points.push_back(point(x, y, z));
  }
  for(int i = 0; i < n; i++){
    int m = INF;
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      m = min(m, dist(points[i], points[j]));
    }
    double in = floor(sqrt(m));
    ans[(int)in]++;
  }
  for(int i = 0; i < 10; i++){
    if(ans[i]) printf("%4.d", ans[i]);
    else printf("   0");
  }
  printf("\n");
}