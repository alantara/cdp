#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define MAX 1123
#define INF 112345678

int _p[MAX], _rank[MAX];

void _make(){
  for(int i = 0; i < MAX; i++){
    _p[i] = i;
    _rank[i] = 0;
  }
}

int _find(int u) { return _p[u] == u ? u: _p[u] = _find(_p[u]); }

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

int n, m;
vector<iii> e;
vector<ii> mst;

int best, sbest;

void kruskal(){
  int ans = 0, u, v, w, x, y;
  ii uv;
  sort(e.begin(), e.end());
  _make();
  for(auto &it: e){
    tie(w, uv) = it; tie(u, v) = uv;
    if(_find(u) != _find(v)){
      _union(u, v);
      ans += w;
      mst.push_back(ii(u, v));
    }
  }
  best = ans;
  ans = INF;
  for(auto &t: mst){
    tie(x, y) = t;
    _make();
    int sum = 0, f = n;
    for(auto &it: e){
      tie(w, uv) = it; tie(u, v) = uv;
      if(u == x && v == y) continue;
      if(_find(u) != _find(v)){
        _union(u, v);
        sum += w;
        f--;
      }
    }
    if(f == 1){
      ans = min(ans, sum);
    }
  }
  sbest = ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &m);
    e.clear();
    mst.clear();
    for(int i = 0; i < m; i++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      e.push_back(iii(w, ii(u, v)));
    }
    kruskal();
    printf("%d %d\n", best, sbest);
  }
  return 0;
}