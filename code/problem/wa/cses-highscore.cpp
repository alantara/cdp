#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define MAX 11234
#define INF 1123456789012345

int n;
vector<ii> adj[MAX];
ll dist[MAX];

int bford(){
  for(int i = 0; i <= n; i++){
    dist[i] = INF;
  }
  dist[1] = 0;
  int change = 0;
  for(int j = 0; j < n; j++){
    change = 0;
    for(int i = 1; i <= n; i++){
      if(dist[i] != INF){
        for(auto [v, wei]: adj[i]){
          if(dist[v] > dist[i] + wei){
            dist[v] = dist[i] + wei;
            change = 1;
          }
        }
      }
    }
  }
  return change;
}

int main(){
  int m, u, v, x;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d %d", &u, &v, &x);
    adj[u].push_back(ii(v, -x));
  }
  if(bford()) printf("-1\n");
  else printf("%lld\n", dist[n] == INF ? -1: -dist[n]);
  return 0;
}