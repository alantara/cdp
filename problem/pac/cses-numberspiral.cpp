#include <bits/stdc++.h>

int n;
long long x, y;

int main(){
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%lld %lld", &y, &x);
    if(x>y){
      if(x%2 == 0){
        printf("%lld\n", (x-1)*(x-1)+y);
      }
      else { 
        printf("%lld\n", x*x-y+1);
      }
    }
    else {
      if(y%2 == 0){
        printf("%lld\n", y*y-x+1);
      }
      else { 
        printf("%lld\n", (y-1)*(y-1)+x);
      }
    }
  }
}
