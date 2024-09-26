#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define MAX 1123

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

int c, s, q;
vector<iii> e;
vector<ii> mst[MAX];
int vis[MAX];

void kruskal(){
  _make();
  sort(e.begin(), e.end());
  for(auto &it: e){
    int w, u, v;
    ii uv;
    tie(w, uv) = it; tie(u, v) = uv;
    if(_find(u) != _find(v)){
      _union(u, v);
      mst[u].push_back(ii(w, v));
      mst[v].push_back(ii(w, u));
    }
  }
}

int bfs(int s, int d){
  if(s == d) return 0;
  if(vis[s]) return -1;
  vis[s] = 1;
  for(auto &it: mst[s]){
    int w, v;
    tie(w, v) = it;
    int r = bfs(v, d);
    if(r >= 0) return max(w, r);
  }
  return -1;
}

int main(){
  int t = 1;
  while(scanf("%d %d %d", &c, &s, &q), c){
    e.clear();
    for(int i = 0; i < MAX; i++){
      mst[i].clear();
    }
    int u, v, w;
    for(int i = 0; i < s; i++){
      scanf("%d %d %d", &u, &v, &w);
      e.push_back(iii(w, ii(u, v)));
    }
    kruskal();
    printf("%s", t == 1 ? "": "\n");
    printf("Case #%d\n", t);
    for(int i = 0; i < q; i++){
      scanf("%d %d", &u, &v);
      for(int i = 0; i < MAX; i++){
        vis[i] = 0;
      }
      int r = bfs(u, v);
      if(r >= 0) printf("%d\n", r);
      else printf("no path\n");
    }
    t++;
  }
  return 0;
}