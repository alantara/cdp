#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;
#define MAX 1123

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

int s, p;
ii v[MAX];
vector<dii> e;

double kruskal(){
  double ans = 0;
  int trees = p;
  sort(e.begin(), e.end());
  for(int i = 0; i < p; i++){
    _p[i] = i;
    _rank[i] = 0;
  }
  for(auto &it: e){
    double w;
    ii vs;
    int i, j;
    tie(w, vs) = it; tie(i, j) = vs;
    if(trees == s) break;
    if(_find(i) != _find(j)){
      _union(i, j);
      ans = w;
      trees--;
    }
  }
  return ans;
}

double dist(int i, int j){
  int x, y, z, w;
  tie(x, y) = v[i]; tie(z, w) = v[j];
  int dx = x-z, dy = y-w;
  return sqrt(dx * dx + dy * dy);
}

int main(){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    e.clear();
    scanf("%d %d", &s, &p);
    for(int i = 0; i < p; i++){
      int x, y;
      scanf("%d %d", &x, &y);
      v[i] = ii(x, y);
    }
    for(int i = 0; i < p; i++){
      for(int j = 0; j < i; j++){
        e.push_back(dii(dist(i, j), ii(i, j)));
      }
    }
    printf("%.2f\n", kruskal());
  }
  return 0;
}