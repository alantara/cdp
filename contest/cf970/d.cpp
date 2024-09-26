#include <bits/stdc++.h>
using namespace std;
#define MAX 212345

int n;
int p[MAX];
char c[MAX];
int memo[MAX], vis[MAX];

int dp(int u){
  if(memo[u] != -1) return memo[u];
  if(vis[u]) return 0;
  vis[u] = 1;
  return memo[u] = dp(p[u]) + (c[u] == '0');
}

void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  dfs(p[u]);
  memo[u] = max(memo[u], memo[p[u]]);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    scanf(" %s", c);
    for(int i = 0; i < n; i++){
      p[i]--;
      memo[i] = -1;
      vis[i] = 0;
    }
    for(int i = 0; i < n; i++){
      if(!vis[i]) dp(i);
    }
    for(int i = 0; i < n; i++) vis[i] = 0;
    for(int i = 0; i < n; i++){
      if(!vis[i]) dfs(i);
    }
    for(int i = 0; i < n; i++) printf("%d%s", memo[i], i == n-1? "\n": " ");
  }
  return 0;
}