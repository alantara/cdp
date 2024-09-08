#include <bits/stdc++.h>

int n;
long long s1 = 0, s2 = 0;

#define MAX 1012345
int a[MAX], b[MAX];
int na = 0, nb = 0;

int main(){
  scanf("%d", &n);

  for(int i = n; i > 0; i--){
    if(s1 > s2){
      s2 += i;
      b[nb] = i;
      nb++;
    }  else{
      s1 += i;
      a[na] = i;
      na++;
    }
  }

  if(s1 == s2){
    printf("YES\n");
    printf("%d\n", na);
    for(int i = 0; i<na; i++){
      printf("%d ", a[i]);
    }
    printf("\n%d\n", nb);
    for(int i = 0; i<nb; i++){
      printf("%d ", b[i]);
    } 
  }else{
    printf("NO");
  }
}
