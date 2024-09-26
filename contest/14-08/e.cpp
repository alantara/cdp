#include <bits/stdc++.h>

int main(){
  int a, b, k;
  scanf("%d %d %d", &a, &b, &k);
  for(int i = 1; i <= k; i++){
    printf("%d ", a*i+b);
  }
  printf("\n");
}