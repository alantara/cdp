#include <bits/stdc++.h>

int n, a, b;

int main(){
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d %d", &a, &b);

    if((a+b) % 3 == 0 && (a <= 2*b) && (b <= 2*a)){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
}
