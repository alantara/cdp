#include <bits/stdc++.h>
using namespace std;

int l, c, r1, r2;

int main(){
  while(scanf("%d %d %d %d", &l, &c, &r1, &r2), l){
    int x = l-r1-r2, y = c-r1-r2;
    if(2*r1 > l || 2*r1 > c || 2*r2 > l || 2*r2 > c || x*x + y*y < (r1+r2) * (r1+r2)) printf("N\n");
    else printf("S\n");
  }
  return 0;
}