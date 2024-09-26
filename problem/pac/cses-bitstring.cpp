#include <bits/stdc++.h>

int n;
long long l=1;

int main(){
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    l= (l*2) % (1000000007);
  }
  printf("%lld", l);
}
