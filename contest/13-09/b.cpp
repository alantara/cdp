#include <bits/stdc++.h>
using namespace std;
#define MAX 1123456

int n, a[MAX], b[MAX];

int main(){
  int t; scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ans = 1;
    for(int i = 0; i < n; i++) ans &= a[i] == b[i];
    if(ans) printf("Bob\n");
    else{
      ans = 1;
      for(int i = 0; i < n; i++) ans &= a[i] == b[n-1-i];
      if(ans) printf("Bob\n");
      else printf ("Alice\n");
    }
  }
  return 0;
}