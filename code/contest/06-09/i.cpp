#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 112345
#define LGMAX 40
#define INF 112345678

int n, l;
map<ii, int> cost;
vector<ii> adj[MAX], adjMST[MAX];
int dist[MAX], vis[MAX], p[MAX], mst;
int t, tin[MAX], tout[MAX], up[MAX][LGMAX], big[MAX][LGMAX];

void prim(){
  mst = 0;
  for(int i = 0; i < n; i++){
    dist[i] = INF;
    vis[i] = 0;
    p[i] = -1;
    adjMST[i].clear();
  }
  priority_queue<ii, vector<ii>, greater<ii>> q;
  q.push(ii(dist[0] = 0, 0));
  while(!q.empty()){
    int u = q.top().second; q.pop();
    if(vis[u]) continue;
    vis[u] = 1; mst += dist[u];
    if(p[u] != -1){
      adjMST[u].push_back(ii(p[u], dist[u]));
      adjMST[p[u]].push_back(ii(u, dist[u]));
    }
    for(auto [v, c]: adj[u]){
      if(dist[v] > c){
        q.push(ii(dist[v] = c, v));
        p[v] = u;
      }
    }
  }
}

void build(int u, int a, int c){
  tin[u] = t++;
  up[u][0] = a;
  big[u][0] = c;
  for(int i = 1; i <= l; i++){
    up[u][i] = up[up[u][i-1]][i-1];
    big[u][i] = max(big[u][i-1], big[big[u][i-1]][i-1]);
  }
  for(auto [v, c]: adjMST[u]){
    if(v != a) build(v, u, c);
  }
  tout[u] = t++;
}

int isAncestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v){
  if(isAncestor(u, v)) return u;
  if(isAncestor(v, u)) return v;
  for(int i = l; i >= 0; i--){
    if(!isAncestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}

int biggestToLCA(int u, int v){
  int a = lca(u, v);
  int uok = 1, vok = 1;
  if(a == u) uok = 0;
  if(a == v) vok = 0;
  int m = 0;
  for(int i = l; i >= 0; i--){
    if(uok && !isAncestor(up[u][i], a)) m = max(m, big[u][i]), u = up[u][i];
    if(vok && !isAncestor(up[v][i], a)) m = max(m, big[v][i]), v = up[v][i];
  }
  if(uok) m = max(m, big[u][0]);
  if(vok) m = max(m, big[v][0]);
  return m;
}

int main(){
  int r, u, v, c, q;
  scanf("%d %d", &n, &r);
  for(int i = 0; i < r; i++){
    scanf("%d %d %d", &u, &v, &c); u--; v--;
    adj[u].push_back(ii(v, c));
    adj[v].push_back(ii(u, c));    
    cost[ii(u, v)] = c;
  }
  prim();
  t = 1;
  l = ceil(log2(n));
  build(0, 0, 0);
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%d %d", &u, &v); u--; v--;
    printf("%d\n", mst - biggestToLCA(u, v) + cost[ii(u, v)]);
  }
}