#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
#define MAX 1123
#define INF 112345678

int n;
ii v[MAX];
vector<id> adj[MAX];
double d[MAX];
int ok[MAX];

double prim(){
  double ans = 0;
  priority_queue<di, vector<di>, greater<di>> p;
  for(int i = 0; i < n; i++){
    d[i] = INF;
    ok[i] = 0;
  }
  p.push(di(d[0] = 0, 0));
  while(!p.empty()){
    int u = p.top().second; p.pop();
    if(ok[u]) continue;
    ok[u] = 1; ans += d[u];
    for(auto &[v, w]: adj[u]){
      if(d[v] > w){
        p.push(di(d[v] = w, v));
      }
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
    for(int i = 0; i < MAX; i++){
      adj[i].clear();
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      int x, y;
      scanf("%d %d", &x, &y);
      v[i] = ii(x, y);
      for(int j = 0; j < i; j++){
        double dt = dist(i, j);
        adj[i].push_back(id(j, dt));
        adj[j].push_back(id(i, dt));
      }
    }
    printf("%.2f\n", prim()/100);
  }  
  return 0;
}