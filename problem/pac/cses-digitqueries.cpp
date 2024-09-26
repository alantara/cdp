#include <bits/stdc++.h>

int q;

int main(){
  scanf("%d", &q);

  for(int i=0; i<q; i++){
    long long k;
    scanf("%lld", &k);

    long long p;
    int b;

    for(p=1, b=1; (9*p)*b < k; p*=10, b++){
      k-=(9*p)*b;
    }

    long long a=p+(k-1)/b;

    for(int j=0; j<b-(k-1)%b - 1; j++){
      a/=10;
    }

    printf("%lld\n", a%10);

  }
}
