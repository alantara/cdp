#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define MAX 312345

int n, a, b;
vector<ii> adj[MAX], adjT[MAX];
set<iii> e;
int t, tin[MAX], tlow[MAX];
int st[MAX], stp, vis[MAX];
int comp[MAX], ncomp;
int artcomp[MAX];

void tarjan(int u, int p){
  tin[u] = tlow[u] = ++t;
  st[stp++] = u;
  vis[u] = 1;
  for(auto &[v, w]: adj[u]){
    if(v == p) continue;
    if(!tin[v]) tarjan(v, u);
    if(vis[v]) tlow[u] = min(tlow[u], tlow[v]);
  }
  if(tin[u] == tlow[u]){
    ncomp++;
    do{
      vis[st[--stp]] = 0;
      comp[st[stp]] = ncomp;
    } while(st[stp] != u);
  }
}

int dfs(int u, int a){
  a += artcomp[u];
  vis[u] = 1;
  if(u == comp[b]) return a > 0;
  int ans = 0;
  for(auto &[v, w]: adjT[u]){
    if(!vis[v]) ans += dfs(v, a + w);
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
    e.insert(iii(x, y, z));
    e.insert(iii(y, x, z));
  }
  scanf("%d %d", &a, &b); a--; b--;
  tarjan(0, 0);
  for(auto &[u, v, w]: e){
    if(comp[u] != comp[v]){
      adjT[comp[u]].push_back(ii(comp[v], w));
      adjT[comp[v]].push_back(ii(comp[u], w));
    } else if(w) {
      artcomp[comp[u]]++;
    }
  }
  for(int i = 0; i < n; i++) vis[i] = 0;
  printf("%s\n", dfs(comp[a], 0) ? "YES": "NO");
  return 0;
}