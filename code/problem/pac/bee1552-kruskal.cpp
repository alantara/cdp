#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;
#define MAX 1123

int n, vs;
ii v[MAX];
vector<dii> e;

int _p[MAX], _rank[MAX];

int _find(int u) { return _p[u] == u ? u: (_p[u] = _find(_p[u])); }

void _union(int u, int v){
  u = _find(u); v = _find(v);
  if(_rank[u] < _rank[v]){
    _p[u] = v;
  } else{
    _p[v] = u;
    if(_rank[u] == _rank[v]){
      _rank[u]++;
    }
  }
}

double kruskal(){
  double ans = 0;
  int a, b;
  for(int i = 0; i < n; i++){
    _p[i] = i; _rank[i] = 0;
  }
  sort(e.begin(), e.end());
  for(auto &[w, p]: e){
    tie(a, b) = p;
    if(_find(a) != _find(b)){
      _union(a, b);
      ans += w;
    }
  }
  return ans;
}

double dist(ii p, ii q){
  int x, y, z, w;
  tie(x, y) = p; tie(z, w) = q;
  int dx = x-z, dy = y-w;
  return sqrt(dx * dx + dy * dy);
}

int main(){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &n);
    vs = 0;
    e.clear();
    for(int i = 0; i < n; i++){
      int x, y;
      scanf("%d %d", &x, &y);
      for(int j = 0; j < vs; j++){
        e.push_back(dii(dist(v[j], ii(x, y)), ii(i, j)));
      }
      v[vs++] = ii(x, y); 
    }
    printf("%.2f\n", kruskal()/100);
  }
  return 0;
}