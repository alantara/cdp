#include <bits/stdc++.h>

int euclid(int a, int b){
  if(b == 0) return a;
  return euclid(b, a%b);
}

int r, r1, r2;

int main(){
  scanf("%d.%d", &r1, &r2);
  r = 100*r1 + r2;
  printf("%d\n", 36000 / euclid(36000, r));
  return 0;
}