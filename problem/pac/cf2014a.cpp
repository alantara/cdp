#include <bits/stdc++.h>
using namespace std;
#define MAX 112

int n, k;
int a[MAX];

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0, held = 0;
    for(int i = 0; i < n; i++){
      if(a[i] >= k) held += a[i];
      else if(held > 0 && a[i] == 0){
        ans++;
        held--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}