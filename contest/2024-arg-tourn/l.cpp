#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int n;
int oddbit[MAX], powerbit[MAX];

void setbit(int i, int delta, int *bit){
  while(i <= n){
    bit[i] += delta;
    i += i & -i;
  }
}

int getbit(int i, int *bit){
  int ans = 0;
  while(i){
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

int main(){
  int q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++){
    int tmp;
    scanf("%d", &tmp);
    if(tmp == (tmp & -tmp)) setbit(i, tmp, powerbit);
    if(tmp & 1) setbit(i, tmp, oddbit);
  }
  for(int i = 0; i < q; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    int odd = getbit(v, oddbit) - getbit(v, oddbit), pow = getbit(v, powerbit) - getbit(u, powerbit);
    printf("%c\n", odd > pow ? 'B': (odd == pow ? 'E': 'A'));
  }
  return 0;
}