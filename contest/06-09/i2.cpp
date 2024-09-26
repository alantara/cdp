#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define INF 112345678
#define MAX 212345
#define LOGMAX 40

int n;
vector<ii> adj[MAX], adjMST[MAX];
map<ii, int> e;
set<ii> eMST;

int p[MAX];
int dist[MAX], vis[MAX], mst;

int l, t, tin[MAX], tout[MAX];
int up[MAX][LOGMAX], m[MAX][LOGMAX];

void prim(){
  mst = 0;
  for(int i = 0; i < n; i++){
    dist[i] = INF;
    vis[i] = 0;
    p[i] = -1;
  }
  priority_queue<ii, vector<ii>, greater<ii>> q;
  q.push(ii(dist[0] = 0, 0));
  while(!q.empty()){
    int u = q.top().second; q.pop();
    if(vis[u]) continue;
    vis[u] = 1; mst += dist[u];
    if(p[u] != -1){
      eMST.insert(ii(p[u], u));
      eMST.insert(ii(u, p[u]));
      adjMST[p[u]].push_back(ii(u, dist[u]));
      adjMST[u].push_back(ii(p[u], dist[u]));
    }
    for(auto [v, c]: adj[u]){
      if(dist[v] > c){
        q.push(ii(dist[v] = c, v));
        p[v] = u;
      }
    }
  }
}

void build_lca(int u, int p, int c){
  tin[u] = t++;
  up[u][0] = p;
  m[u][0] = c;
  for(int i = 1; i <= l; i++){
    up[u][i] = up[up[u][i-1]][i-1];
    m[u][i] = max(m[u][i-1], m[up[u][i-1]][i-1]);
  }
  for(auto [v, w]: adjMST[u]){
    if(v != p) build_lca(v, u, w);
  }
  tout[u] = t++;
}

int is_ancestor(int u, int v){
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  for(int i = l; i >= 0; i--){
    if(!is_ancestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}

int max_edge(int u, int v){
  int a = lca(u, v);
  int bg = 0;
  for(int i = l; i >= 0; i--){
    if(!is_ancestor(up[u][i], a)){
      bg = max(bg, m[u][i]);
      u = up[u][i];
    }
    if(!is_ancestor(up[v][i], a)){
      bg = max(bg, m[v][i]);
      v = up[v][i];
    }
  }
  if(u != a) bg = max(bg, m[u][0]);
  if(v != a) bg = max(bg, m[v][0]);
  return bg;
}

int main(){
  int r, a, b, c, q;
  scanf("%d %d", &n, &r);
  for(int i = 0; i < r; i++){
    scanf("%d %d %d", &a, &b, &c); a--; b--;
    e[ii(a, b)] = c;
    e[ii(b, a)] = c;
    adj[a].push_back(ii(b, c));
    adj[b].push_back(ii(a, c));
  }
  prim();
  l = ceil(log2(n));
  build_lca(0, 0, 0);
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%d %d", &a, &b); a--; b--;
    long long ans = mst;
    if(eMST.find(ii(a, b)) == eMST.end()) ans += e[ii(a, b)] - max_edge(a, b);
    printf("%lld\n", ans);
  }
  return 0;
}