#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 212345

int n, m, q;
ii e[MAX];
int fr[MAX];
int st[MAX], stp = 0;
int ansv[MAX], nansv = 0;

int _p[MAX], _rank[MAX];

int _find(int u){ return (_p[u] == u) ? u: (_p[u] = _find(_p[u])); }

void _union(int u, int v){
  u = _find(u); v = _find(v);
  if(_rank[v] > _rank[u]){
    _p[u] = v;
  }
  else{
    _p[v] = u;
    if(_rank[u] == _rank[v]){
      _rank[u]++;
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    _p[i] = i;
  }
  for(int i = 1; i <= m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    e[i] = ii(a, b);
  }
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    int a;
    scanf("%d", &a);
    st[stp++]=a;
    fr[a] = 1;
  }
  int ans = n;
  for(int i = 1; i <= m; i++){
    if(fr[i] > 0) continue;
    int a = e[i].first, b = e[i].second;
    if(_find(a) != _find(b)){
      _union(a, b);
      ans--;
    }
  }
  while(stp != 0){
    ansv[nansv++] = ans;
    stp--;
    int a = e[st[stp]].first, b = e[st[stp]].second;
    if(_find(a) != _find(b)){
      _union(a, b);
      ans--;
    }
  }
  for(int i = 0; i < nansv; i++){
    printf("%s%d", (i==0)? "": " ", ansv[nansv-1-i]);
  }
  printf("\n");
  return 0;
}