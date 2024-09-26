#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", min(k, m) * min(k, n));
  }
  return 0;
}