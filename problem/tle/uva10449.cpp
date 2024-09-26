#include <bits/stdc++.h>
using namespace std;
#define MAX 1123
#define INF 112345678

int n, busy[MAX];
vector<int> adj[MAX];
int dist[MAX];

void bford(){
  for(int i = 1; i <= n; i++){
    dist[i] = INF;
  }
  dist[1] = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 1; j <= n; j++){
      if(dist[j] == INF) continue;
      for(auto it: adj[j]){
        int dif = busy[it] - busy[j];
        int w = dif*dif*dif;
        if(dist[it] > dist[j] + w){
          dist[it] = dist[j] + w;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(dist[i] == INF) dist[i] = -1;
  }
}

int main(){
  int r, u, v, q;
  for(int t = 1; scanf("%d", &n) != EOF; t++){
    for(int i = 0; i < MAX; i++){
      adj[i].clear();
    }
    for(int i = 1; i <= n; i++){
      scanf("%d", &busy[i]);
    }
    scanf("%d", &r);
    for(int i = 0; i < r; i++){
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
    }
    bford();
    scanf("%d", &q);
    printf("Set #%d\n", t);
    while(q--){
      scanf("%d", &v);
      if(dist[v] < 3) printf("?\n");
      else printf("%d\n", dist[v]);
    }
  }
  return 0;
}