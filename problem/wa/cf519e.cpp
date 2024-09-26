#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
#define LOGMAX 30

int n;
vector<int> adj[MAX];
int t, l;
int tin[MAX], tout[MAX];
int up[MAX][LOGMAX];
int vis[MAX], dfsnum[MAX];

int dfs(int u){
  vis[u] = 1;
  int ans = 0;
  for(auto v: adj[u]){
    if(!vis[v]) ans += dfs(v);
  }
  return dfsnum[u] = 1 + ans;
}

void build(int u, int p){
  tin[u] = t++;
  up[u][0] = p;
  for(int i = 1; i <= l; i++){
    up[u][i] = up[up[u][i-1]][i-1];
  }
  for(auto v: adj[u])
    if(v != p) build(v, u);
  tout[u] = t++;
}

int anc(int u, int v){ return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int lca(int u, int v){
  if(anc(u, v)) return u;
  if(anc(v, u)) return v;
  for(int i = l; i >= 0; i--)
    if(!anc(up[u][i], v)) u = up[u][i];
  return up[u][0];
}

int query(int u, int v){
  if(u == v) return n;
  int a = lca(u, v);
  int _u = u, _v = v;
  int c = 0;
  for(int i = l; i >= 0; i--){
    if(!anc(up[_u][i], a)){
      _u = up[_u][i];
      c += (1 << i);
    }
    if(!anc(up[_v][i], a)){
      _v = up[_v][i];
      c += (1 << i);
    }
  }
  if(u != a) c++;
  if(v != a) c++;
  if(c & 1) return 0;
  int r = a, l1 = 0, l2 = 0;
  for(int i = l; i >= 0; i--){
    if(!anc(up[u][i], a) && l1 + (1 << i) < c/2){
      u = up[u][i];
      l1 += (1 << i);
    }
    if(!anc(up[v][i], a) && l2 + (1 << i) < c/2){
      v = up[v][i];
      l2 += (1 << i);
    }
  }
  int ans = 0;
  if(l1 + 1 == c/2){
    r = up[u][0];
    if(r != a) ans = dfsnum[r] - dfsnum[u];
    else ans = n - dfsnum[u];
  }
  if(l2 + 1 == c/2){
    r = up[v][0];
    if(r != a) ans = dfsnum[r] - dfsnum[v];
    else ans = ans - dfsnum[v];
  }
  return ans;
}

int main(){
  int u, v, q;
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++){
    scanf("%d %d", &u, &v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  l = ceil(log2(n));
  build(0, 0);
  dfs(0);
  scanf("%d", &q);
  while(q--){
    scanf("%d %d", &u, &v); u--; v--;
    printf("%d\n", query(u, v));
  }
  return 0;
}