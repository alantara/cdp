#include <bits/stdc++.h>

#define MAX 1012345
int a[MAX];
int n;

int main(){
  scanf("%d", &n);

  int l = 1;
  for(int i = (n-1)/2; i>=0; i--){
    a[i]=l;
    l+=2;
  }

  l=2;
  for(int i = n-1; i > (n-1)/2; i--){
    a[i]=l;
    l+=2;
  }

  int y = 1;
  for(int i = 1; i<n; i++){
    if(a[i]-a[i-1] == 1 || a[i-1]-a[i] == 1){
      y=0;
    }
  }

  if(y){
    for(int i = 0; i < n; i++){
      printf("%d ", a[i]);
    }
  }
  else{
    printf("NO SOLUTION");
  }
}
