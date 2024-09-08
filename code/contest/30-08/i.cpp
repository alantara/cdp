#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 112345

int _p[MAX], _rank[MAX], _size[MAX];

int _find(int u){ return _p[u] == u ? u: _find(_p[u]); }

void _union(int u, int v){
  u = _find(u); v = _find(v);
  if(_rank[u] < _rank[v]){
    _p[u] = v;
    _size[v] += _size[u];
  } else{
    _p[v] = u;
    _size[u] += _size[v];
    if(_rank[u] == _rank[v]){
      _rank[u]++;
    }
  }
}

int n, m;
int vis[MAX];

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    _p[i] = i;
    _rank[i] = 0;
    _size[i] = 1;
    vis[i] = 0;
  }
  while(m--){
    int u, v;
    scanf("%d %d", &u, &v);
    if(_find(u) != _find(v)){
      _union(u, v);
    }
  }
  ll ans = 1;
  for(int i = 0; i < n; i++){
    int u = _find(i);
    if(vis[u] == 0){
      vis[u] = 1;
      ans = (ans * _size[u]) % 1000000007;
    }
  }
  printf("%lld\n", ans);
  return 0;
}