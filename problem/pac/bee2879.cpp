#include <bits/stdc++.h>

int main(){
  int n, ans = 0;
  scanf("%d", &n);
  while(n--){
    int a;
    scanf("%d", &a);
    if(a != 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}