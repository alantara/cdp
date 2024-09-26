#include <bits/stdc++.h>
using namespace std;
#define MAX 1123

int n;
vector<int> adj[MAX];
int gDAG[MAX], adjDAG[MAX][MAX];

int nSCC, cnt;
int tnum[MAX], tlow[MAX];
int vis[MAX], st[MAX], stp;
int ncomp, comp[MAX];

void tarjan(int u){
  tnum[u] = tlow[u] = cnt++;
  st[stp++] = u;
  vis[u] = 1;
  for(auto v: adj[u]){
    if(!tnum[v]) tarjan(v);
    if(vis[v]) tlow[u] = min(tlow[u], tlow[v]);
  }
  if(tnum[u] == tlow[u]){
    nSCC++;
    do{
      vis[st[--stp]] = 0;
      comp[st[stp]] = ncomp;
    } while(st[stp] != u);
    ncomp++;
  }
}

void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  for(int v = 0; v < ncomp; v++){
    if(adjDAG[u][v]) dfs(v);
  }
}

int main(){
  int m, u, v, t;
  while(scanf("%d %d", &n, &m) != EOF){
    for(int i = 0; i < n; i++){
      adj[i].clear();
      gDAG[i] = 0;
      for(int j = 0; j < n; j++){
        adjDAG[i][j] = 0;
      }
    }
    for(int i = 0; i < m; i++){
      scanf("%d %d %d", &u, &v, &t); u--; v--;
      if(i == 0) continue;
      adj[u].push_back(v);
      if(t >> 1) adj[v].push_back(u);
    }
    nSCC = 0; cnt = 1; ncomp = 0;
    for(int i = 0; i < n; i++){
      tnum[i] = tlow[i] = 0;
      comp[i] = 0;
      vis[i] = 0;
    }
    for(int i = 0; i < n; i++)
      if(!tnum[i]) tarjan(i);
    if(nSCC == 1){
      printf("-\n");
      continue;
    }
    for(u = 0; u < n; u++)
      for(auto v: adj[u])
        if(comp[u] != comp[v]){
          adjDAG[comp[u]][comp[v]] = 1;
          adjDAG[comp[v]][comp[u]] = 1;
          gDAG[comp[u]]++;
          gDAG[comp[v]]++;
        }
    int nCC = 0;
    for(int i = 0; i < n; i++) vis[i] = 0;
    for(int i = 0; i < ncomp; i++)
      if(!vis[i]){
        dfs(i);
        nCC++;
      }
    if(nCC > 1){
      printf("*\n");
      continue;
    }
    int deg2 = 1;
    for(int i = 0; i < ncomp; i++){
      deg2 &= gDAG[i] > 1;
    }
    printf("%s\n", deg2 ? "1": "2");
  }
  return 0;
}