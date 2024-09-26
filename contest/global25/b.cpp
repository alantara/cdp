#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int n, k;
int a[MAX];

int solve(int u){
  int ans = 0;
  for(int i = u+1; i < n; i++){
    if(a[i] < a[u]) ans++;
    else break;
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int ans = 0;
    scanf("%d %d", &n, &k); k--;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    swap(a[0], a[k]);
    ans = max(ans, solve(0));
    swap(a[0], a[k]);
    int p = 0;
    for(int i = 0; i < k; i++){
      if(a[i] > a[k]){
        p = i;
        break;
      }
    }
    swap(a[p], a[k]);
    ans = max(ans, solve(p) + (int)(p != 0));
    printf("%d\n", ans);
  }
  return 0;
}