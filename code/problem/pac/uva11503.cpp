#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

map<string, string> _p;
map<string, int> _rank, _f;

string _find(string p){
  return (_p[p].compare(p) == 0) ? p : _p[p] = _find(_p[p]);
}

void _union(string p, string q){
  p = _find(p); q = _find(q);
  if(_rank[p] > _rank[q]){
    _p[q] = p;
    _f[p] += _f[q];
  }
  else{
    _p[p] = q;
    _f[q] += _f[p];
    if(_rank[p] == _rank[q]){
      _rank[q]++;
    }
  }
}

int main(void){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    _p.clear();
    _rank.clear();
    _f.clear();
    int f;
    scanf("%d", &f);
    while(f--){
      char p[25], q[25];
      scanf(" %s %s", p, q);
      if(_p[p].empty())
        _p[p] = p;
      if(_p[q].empty())
        _p[q] = q;
      if(_f[p] == 0)
        _f[p] = 1;
      if(_f[q] == 0)
        _f[q] = 1;
      if(_find(p) != _find(q))
        _union(p, q);
      printf("%d\n", _f[_find(p)] );
    }
  }
  return 0;
}