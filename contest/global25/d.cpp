#include <bits/stdc++.h>
typedef long long ll;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    ll n, k;
    scanf("%lld %lld", &n, &k);
    if(n/k < 2 && n != k) printf("NO\n");
    else{
      printf("YES\n");
      printf("1\n");
      printf("%lld\n", n/k);
    }
  }
  return 0;
}