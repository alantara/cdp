#include <bits/stdc++.h>
#define MAX 212345

int n, bit[MAX], p[MAX];
char a; int c;

int getbit(int i){
  int ans = 0;
  while(i){
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void setbit(int i, int delta){
  while(i <= n){
    bit[i] += delta;
    i += i & -i;
  }   
}

int main(void){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int pi;
    scanf("%d", &pi);
    p[i] = pi;
    setbit(i, pi);
  }
  while(scanf(" %c %d", &a, &c) != EOF){
    switch(a){
      case 'a':
      setbit(c, -p[c]);
      break;
      case '?':
      printf("%d\n", getbit(c-1 ));
      break;
    }
  }
  return 0;
}