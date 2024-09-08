#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int t, n, h[MAX], x[MAX];

int solve(){
  int m = 0, ans = 1;
  for(int i = 0; i < n-1; i++){
    if(max(m, h[i]) <= x[i]) ans = 0;
    m = max(h[i] - x[i], m - x[i]);
  }
  return ans;
}

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &h[i]);
    }
    for(int i = 0; i < n-1; i++){
      scanf("%d", &x[i]);
    }
    int ans = solve();
    reverse(h, h+n);
    reverse(x, x+n-1);
    ans |= solve();
    printf("%s\n", ans ? "habibi": "which");
  }
  return 0;
}