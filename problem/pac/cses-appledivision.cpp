#include <bits/stdc++.h>

int a[20];
int n;

long long rapple(int i, long long s1, long long s2){
  if(i==0){
    return (s1-s2 > 0) ? s1-s2 : s2-s1;
  }

  long long d1 = rapple(i-1, s1+a[i-1], s2);
  long long d2 = rapple(i-1, s1, s2+a[i-1]);

  return (d1 > d2) ? d2 : d1;
}

int main(){
  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }

  long long r= rapple(n, 0, 0);

  printf("%lld", r);
}
