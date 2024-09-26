#include <bits/stdc++.h>
#define MAX 212345

int n, a[MAX], gdc1[MAX], gdc2[MAX];

int main(void){
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    if(i == 0){
      gdc1[i] = a[i];
      gdc2[i] = a[i];
    }
    if(i > 0){
      gdc1[i] = euclid(a[i], gdc1[i-1]);
      if(i > 1){
        gdc2[i-1] = euclid(a[i], gdc2[i-2]);
      }
    }
  }
  int max = 0, sum = 0;
  for(i = 0; i < n-1; i++){
    sum+=gdc1[i];
    if(max < gdc2[i] - gdc1[i]){
      max = gdc2[i] - gdc1[i];
      
    }
  }
  return 0;
}