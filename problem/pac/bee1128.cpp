#include <bits/stdc++.h>
using namespace std;
#define MAX 11234

int n;
vector<int> adj[MAX];

int numSCC, counter;
int bfs_num[MAX], bfs_low[MAX];
int vis[MAX], st[MAX], stp;

void tarjan(int u){
  if(bfs_num[u]) return;
  bfs_num[u] = bfs_low[u] = counter++;
  st[stp++] = u;
  vis[u] = 1;
  for(auto v: adj[u]){
    tarjan(v);
    if(vis[v]) bfs_low[u] = min(bfs_low[u], bfs_low[v]);
  }
  if(bfs_num[u] == bfs_low[u]){
    numSCC++;
    do{
      vis[st[--stp]] = 0;
    } while(st[stp] != u);
  }
}

int main(){
  int m, u, v, d;
  while(scanf("%d %d", &n, &m), n){
    numSCC = 0; counter = 1;
    for(int i = 0; i < n; i++){
      adj[i].clear();
      bfs_num[i] = bfs_low[i] = 0;
    }
    for(int i = 0; i < m; i++){
      scanf("%d %d %d", &u, &v, &d); u--; v--;
      adj[u].push_back(v);
      if(d >> 1) adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) tarjan(i);
    printf("%d\n", numSCC == 1 ? numSCC: 0);
  }
  return 0;
}