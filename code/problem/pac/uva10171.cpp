#include <bits/stdc++.h>
using namespace std;
#define MAX 112
#define INF 112345678
typedef pair<int, int> ii;

int n;
vector<ii> yng[MAX], mt[MAX];
int distyn[MAX], distmt[MAX];
int visyn[MAX], vismt[MAX];

void dijkstra(int s, vector<ii>* adj, int* dist, int* vis){
  for(int i = 0; i < 26; i++){
    dist[i] = INF;
    vis[i] = 0;
  }
  priority_queue<ii, vector<ii>, greater<ii>> q;
  q.push(ii(dist[s] = 0, s));
  while(!q.empty()){
    int u = q.top().second; q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto [v, wei]: adj[u]){
      if(dist[v] > dist[u] + wei){
        dist[v] = dist[u] + wei;
        q.push(ii(dist[v], v));
      }
    }
  }
}

int main(){
  char age, dir, a, b;
  int u, v, wei;
  while(scanf("%d", &n), n){
    for(int i = 0; i < 26; i++){
      yng[i].clear();
      mt[i].clear();
    }
    for(int i = 0; i < n; i++){
      scanf(" %c %c %c %c %d", &age, &dir, &a, &b, &wei);
      u = a-'A';
      v = b-'A';
      if(age == 'Y'){
        yng[u].push_back(ii(v, wei));
        if(dir == 'B') yng[v].push_back(ii(u, wei));
      } else{
        mt[u].push_back(ii(v, wei));
        if(dir == 'B') mt[v].push_back(ii(u, wei));
      }
    }
    scanf(" %c %c", &a, &b);
    u = a-'A';
    v = b-'A';
    dijkstra(u, yng, distyn, visyn);
    dijkstra(v, mt, distmt, vismt);
    int m = INF;
    for(int i = 0; i < 26; i++){
      if(distyn[i] != INF && distmt[i] != INF) m = min(m, distyn[i] + distmt[i]);
    }
    if(m == INF) printf("You will never meet.\n");
    else{
      printf("%d", m);
      for(int i = 0; i < 26; i++) 
        if(distyn[i] + distmt[i] == m) printf(" %c", 'A' + i);
      printf("\n");
    }
  }
  return 0;
}