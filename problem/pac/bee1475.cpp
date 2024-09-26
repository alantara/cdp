#include <bits/stdc++.h>
using namespace std;
#define INF 1123412341
#define MAX 1123

int n, c, t1, t2;
int f[2*MAX], nx[2*MAX][2];
int s[2*MAX];

void build_nx(){
  for(int i = 0; i < 2*n; i++){
    int j;
    for(j = i; j < 2*n && f[j] <= f[i] + t1; j++);
    nx[i][0] = j;
    for(j = i; j < 2*n && f[j] <= f[i] + t2; j++);
    nx[i][1] = j;
  }
}

int dp(int ind, int n){
  if(s[ind] != -1) return s[ind];
  if(n <= 0) return 0;
  int n1 = nx[ind][0], n2 = nx[ind][1];
  return s[ind] = min(t1 + dp(n1, n - (n1 - ind)), t2 + dp(n2, n - (n2 - ind)));
}

int main(){
  while(scanf("%d %d %d %d", &n, &c, &t1, &t2) != EOF){
    for(int i = 0; i < n; i++) scanf("%d", &f[i]);
    for(int i = 0; i < n; i++) f[i+n] = f[i] + c;
    build_nx();
    int ans = INF;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < 2*MAX; j++) s[j] = -1;
      ans = min(ans, dp(i, n));
    }
    printf("%d\n", ans);
  } 
  return 0;
}