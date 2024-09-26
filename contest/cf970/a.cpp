#include <bits/stdc++.h>
using namespace std;
#define MAX 11

int a, b;
int memo[2*MAX][3*MAX];

int dp(int n, int s){
  if(memo[n][s] != -1) return memo[n][s];
  if(n >= a+b) return s;
  int sm = n < a ? 1: 2;
  return memo[n][s] = dp(n+1, s+sm) && dp(n+1, s-sm);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    for(int i = 0; i < 2*MAX; i++){
      for(int j = 0; j < 3*MAX; j++) memo[i][j] = -1;
    }
    scanf("%d %d", &a, &b);
    printf("%s\n", !dp(0, 0) ? "YES": "NO");
  }
  return 0;
}