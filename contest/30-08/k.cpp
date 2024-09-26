#include <bits/stdc++.h>
using namespace std;
#define MAX 1123

int n, m;
char l[MAX][MAX];
int vis[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(int u, int v){
  if(vis[u][v]) return 0;
  vis[u][v] = 1;
  for(int i = 0; i < 4; i++){
    int du = u + dx[i], dv = v + dy[i];
    if(du >= 0 && du < n && dv >= 0 && dv < m && l[du][dv] == 'T'){
      char c = l[u][v];
      return (c >= '1' && c <= '9') ? c-'0': 0;
    }
  }
  int ans = 0;
  for(int i = 0; i < 4; i++){
    int du = u + dx[i], dv = v + dy[i];
    if(du >= 0 && du < n && dv >= 0 && dv < m && l[du][dv] != '#'){
      ans += dfs(du, dv);
    }
  }
  char c = l[u][v];
  return(c >= '1' && c <= '9') ? ans + c-'0': ans;
}

int main(){
  int u = 0, v = 0;
  while(scanf("%d %d", &n, &m) != EOF){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        vis[i][j] = 0;
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        scanf(" %c", &l[i][j]);
        if(l[i][j] == 'S'){
          u = i;
          v = j;
        }
      }
    }
    printf("%d\n", dfs(u, v));
  }
  return 0;
}