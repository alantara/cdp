#include <bits/stdc++.h>
#define MAX 112345

char s[MAX];
int n, w[MAX];

int main(){
  scanf(" %s", s);
  for(n = 0; s[n] != '\0'; n++);
  for(int i = 1; i < n; i++){
    if(w[i] == 1) continue;
    int ok = 0;
    for(int j = 0; j < i; j++){
      if(s[j] == 'P') continue;
      int rocks = 1;
      for(int k = (j+i) % n; k != j; k=(k+i) % n) rocks &= s[k] == 'R';
      if(rocks) ok |= 1;
    }
    if(ok){
      for(int j = i; j < n; j+=i){
        w[j] = 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(w[i] == 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}