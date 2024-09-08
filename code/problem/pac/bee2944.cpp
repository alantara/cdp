#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int v;
vector<int> adj[MAX], ts;
int vis[MAX];

void tsort(int u){
  if(vis[u]) return;
  vis[u] = 1;
  for(auto v: adj[u]){
    tsort(v);
  }
  ts.push_back(u);
}

void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  for(auto v: adj[u]){
    dfs(v);
  }
}

int main(){
  int e, s, x, y;
  scanf("%d %d %d", &v, &e, &s); s--;
  for(int i = 0; i < e; i++){
    scanf("%d %d", &x, &y); x--; y--;
    adj[x].push_back(y);
  }
  for(int i = 0; i < v; i++){
    if(!vis[i]) tsort(i);
  }
  reverse(ts.begin(), ts.end());
  for(int i = 0; i < v; i++) vis[i] = 0;
  int ans = 0;
  dfs(s);
  for(auto i: ts){
    if(!vis[i]){
      dfs(i);
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}