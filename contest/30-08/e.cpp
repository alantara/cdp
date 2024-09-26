#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int root = sqrt(n);
  for(int i = 2; i <= root; i++){
    while(n%i == 0){
      n /= i;
      printf("%d", i);
      if(n != 1){
        printf("x");
      }
    }
  }
  if(n != 1){
    printf("%d", n);
  }
  printf("\n");

  return 0;
}