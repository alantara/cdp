#include <bits/stdc++.h>
using namespace std;

int n, m;
int vis[1123], v[1123];
vector<vector<int>> adj(1123);

int dfs(int i){
  if(vis[i]) return 0;
  vis[i] = 1;
  int b = 0;
  for(auto &e : adj[i]){
    b += dfs(e);
  }
  return v[i] == 1 ? b+1: b;
}

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    for(int i = 0; i < n; i++){
      char t;
      scanf(" %c", &t);
      v[i] = t-'A';
      vis[i] = 0;
      adj[i].clear();
    }
    for(int i = 0; i < m; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
      if(vis[i] == 0){
        ans &= ((dfs(i) % 2) == 0);
      }
    }
    printf("%s\n", ans ? "Y" : "N");
  }
  return 0;
}