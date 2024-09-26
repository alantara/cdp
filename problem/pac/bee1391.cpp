#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 1123
#define INF 112345678

int n, m;
int s, d;
int u, v, w;
int adj[MAX][MAX];
int dist[MAX], vis[MAX];
vector<int> ret[MAX];

void remove(int r){
  for(auto a: ret[r]){
    adj[a][r] = 0;
    remove(a);
  }
}

int dijkstra(){
  for(int i = 0; i < MAX; i++){
    dist[i] = INF;
    vis[i] = 0;
    ret[i].clear();
  }
  priority_queue<ii, vector<ii>, greater<ii>> q;
  dist[s] = 0;
  q.push(ii(0, s));
  while(!q.empty()){
    u = q.top().second; q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(int i = 0; i < MAX; i++){
      if((w = adj[u][i]) == 0) continue;
      if(dist[i] == dist[u] + w) ret[i].push_back(u);
      else if(dist[i] > dist[u] + w){
        dist[i] = dist[u] + w;
        ret[i].clear();
        ret[i].push_back(u);
        q.push(ii(dist[i], i));
      }
    }
  }
  return dist[d];
}

int main(){
  while(scanf("%d %d", &n, &m), n){
    for(int i = 0; i < MAX; i++){
      for(int j = 0; j < MAX; j++){
        adj[i][j] = 0;
      }
    }
    scanf("%d %d", &s, &d);
    for(int i = 0; i < m; i++){
      scanf("%d %d %d", &u, &v, &w);
      adj[u][v] = w;
    }
    dijkstra();
    remove(d);
    int ans = dijkstra();
    printf("%d\n", ans == INF ? -1: ans); 
  }
  return 0;
}