#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define MAX 312345

int n, a, b;
vector<ii> adj[MAX], adjT[MAX];
set<iii> bridges;
int t, tin[MAX], tlow[MAX];
int vis[MAX], comp[MAX], ncomp;
int artcomp[MAX];

void find_bridges(int u, int p){
  tin[u] = tlow[u] = ++t;
  for(auto &[v, w]: adj[u]){
    if(v == p) continue;
    if(!tin[v]){
      find_bridges(v, u);
      if(tlow[v] > tin[u]){
        bridges.insert(iii(u, v, w));
        bridges.insert(iii(v, u, w));
      }
    }
    tlow[u] = min(tlow[u], tlow[v]);
  }
}

void map_components(int u){
  comp[u] = ncomp;
  vis[u] = 1;
  for(auto &[v, w]: adj[u]){
    if(bridges.find(iii(u, v, w)) == bridges.end()){
      if(!vis[v]) map_components(v);
      if(w) artcomp[ncomp]++;
    }
  }
}

int dfs(int u, int z){
  z += artcomp[u];
  vis[u] = 1;
  if(u == comp[b]) return z > 0;
  int ans = 0;
  for(auto &[v, w]: adjT[u]){
    if(!vis[v]) ans |= dfs(v, z + w);
  }
  return ans;
}

int main(){
  int m, x, y, z;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d %d", &x, &y, &z); x--; y--;
    adj[x].push_back(ii(y, z));
    adj[y].push_back(ii(x, z));
  }
  scanf("%d %d", &a, &b); a--; b--;
  find_bridges(0, 0);
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      ncomp++;
      map_components(i);
    }
  }
  for(auto &[u, v, w]: bridges){
    adjT[comp[u]].push_back(ii(comp[v], w));
    adjT[comp[v]].push_back(ii(comp[u], w));
  }
  for(int i = 0; i < n; i++) vis[i] = 0;
  printf("%s\n", dfs(comp[a], 0) ? "YES": "NO");
  return 0;
}