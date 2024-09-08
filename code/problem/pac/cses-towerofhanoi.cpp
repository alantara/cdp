#include <bits/stdc++.h>

int hanoi(int n){
  if(n == 1){
    return 1;
  }
  return 2*hanoi(n-1) + 1;
}

void phanoi(int n, int now, int aux, int dest){
  if(n == 1){
    printf("%d %d\n", now, dest);
    return;
  }

  phanoi(n-1, now, dest, aux);
  phanoi(1, now, aux, dest);
  phanoi(n-1, aux, now, dest);
}

int n;

int main(){
  scanf("%d", &n);
  int i = hanoi(n);
  printf("%d\n", i);
  phanoi(n, 1, 2, 3);
}
