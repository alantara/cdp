#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int n;
vector<int> adj[MAX], adjDAG[MAX];

vector<int> ts;

int cnt;
int num[MAX], low[MAX];
int vis[MAX], st[MAX], stp;
int comp[MAX], ncomp;

void tarjan(int u){
  num[u] = low[u] = ++cnt;
  st[stp++] = u;
  vis[u] = 1;
  for(auto v: adj[u]){
    if(!num[v]) tarjan(v);
    if(vis[v]) low[u] = min(low[u], low[v]);
  }
  if(num[u] == low[u]){
    do{
      vis[st[--stp]] = 0;
      comp[st[stp]] = ncomp;
    } while(st[stp] != u);
    ncomp++;
  }
}

void tsort(int u){
  if(vis[u]) return;
  vis[u] = 1;
  for(auto v: adjDAG[u]){
    tsort(v);
  }
  ts.push_back(u);
}

int main(){
  int m, u, v;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d", &u, &v); u--; v--;
    adj[u].push_back(v);
  }
  for(u = 0; u < n; u++){
    if(!num[u]) tarjan(u);
  }
  for(u = 0; u < n; u++){
    for(auto v: adj[u]){
      if(comp[u] != comp[v]) {
        adjDAG[comp[u]].push_back(comp[v]);
      }
    }
  }
  for(int i = 0; i < ncomp; i++) vis[i] = 0;
  for(u = 0; u < ncomp; u++) tsort(u);
  reverse(ts.begin(), ts.end());
  int ans = 1;
  for(u = 0; u < ncomp - 1; u++){
    int has = 0;
    for(auto v: adjDAG[ts[u]]){
      has |= (v == ts[u+1]);
    }
    ans &= has;
  }
  printf("%sBolada\n", ans ? "": "Nao ");
  return 0;
}