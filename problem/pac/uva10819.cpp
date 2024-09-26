#include <bits/stdc++.h>
using namespace std;
#define MAXM 11234
#define MAXN 112

int m, n;
int p[MAXN], f[MAXN];
int s[MAXM][MAXN];

int dp(int mon, int b){
  if(s[mon][b] != -1) return s[mon][b];
  if(b == n) return 0;
  int ans = 0, inc = 0;
  if(mon + p[b] > 2000) inc = 200;
  if(m - mon + inc >= p[b]) ans = f[b] + dp(mon + p[b], b+1);
  return s[mon][b] = max(ans, dp(mon, b+1));
}

int main(){
  while(scanf("%d %d", &m, &n) != EOF){
    for(int i = 0; i < n; i++){
      scanf("%d %d", &p[i], &f[i]);
    }
    for(int i = 0; i < MAXM; i++){
      for(int j = 0; j < MAXN; j++) s[i][j] = -1;
    }
    printf("%d\n", dp(0, 0));
  }
  return 0;
}