#include <bits/stdc++.h>

int n;
int s = 0;

int main(){
  scanf("%d", &n);

  for(int i = 5; i <= n; i=i*5){
    s+=n/i;
  }
  printf("%d", s);
}
