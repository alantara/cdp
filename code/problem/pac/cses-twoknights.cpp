#include <bits/stdc++.h>

int n;
long long l;

int main(){
  scanf("%d", &n);

  for(long long i = 1; i<=n; i++){
    l=(i-4)*(i-4)*(i*i-9) + 4*(i-4)*(i*i-7)+4*(i-4)*(i*i-5) + 4*(i*i-5)+8*(i*i-4)+4*(i*i-3);
    l/=2;
    printf("%lld\n", l);
  }
}
