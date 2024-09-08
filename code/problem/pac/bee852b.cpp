#include <bits/stdc++.h>
using namespace std;
#define MAX 212345
typedef tuple<int, int, int> iii;

int n, m, k, i, u, v, c;
int _p[MAX], _rank[MAX], _size[MAX];
iii l[MAX];

int _find(int u){
  return (_p[u] == u) ? u : _p[u] = _find(_p[u]);
}

int _union(int u, int v){
  u = _find(u); v = _find(v);
  int s = _size[u] + _size[v];
  if(_rank[u] > _rank[v]){
    _p[v] = u;
    _size[u] = s;
    return u;
  }
  else{
    _p[u] = v;
    _size[v] = s;
    if(_rank[u] == _rank[v]){
      _rank[v]++;
    }
    return v;
  }
}

int main(void){
  scanf("%d %d %d", &n, &m, &k);
  for(i = 0; i < n; i++){
    _p[i] = i;
    _size[i] = 1;
  }
  for(i = 0; i < m; i++){
    scanf("%d %d %d", &u, &v, &c);
    l[i] = iii(c, u, v);
  }
  sort(l, l+m);
  int end = 0;
  for(i = 0; i < m && !end; i++){
    c = get<0>(l[i]);
    u = get<1>(l[i]);
    v = get<2>(l[i]);
    if(_find(u) != _find(v)){
      int ret = _union(u, v);
      if(_size[ret] >= k){
        end = 1;
        printf("%d\n", c);
      }
    }
  }
  return 0;
}