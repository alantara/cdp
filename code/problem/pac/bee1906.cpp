#include <bits/stdc++.h>
using namespace std;
#define MAX 11234567

int n, k;
int vis[MAX];

int dfs(int i){
  if(i > n) return 1;
  if(vis[i]) return k;
  int r = dfs(i & 1 ? 3*i + 1: i/2);
  if(r >= k){
    vis[i] = 1;
  }
  return r+1;
}

int main(){
  for(int i = 0; i < MAX; i++){
    vis[i] = 0;
  }
  scanf("%d %d", &n, &k);
  if((n == 1 && k > 1) || (n < 4 && k > 2)){
    printf("0\n");
    return 0;
  }
  vis[1] = 1;
  for(int i = n; i > 0; i--){
    dfs(i);
  }
  int ans = 0;
  for(int i = 0; i <= n; i++){
    ans += vis[i];
  }
  printf("%d\n", ans);
  return 0;
}