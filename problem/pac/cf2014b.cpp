#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%s\n", (((n-k+1)+n)*k/2)&1 ? "NO": "YES");
  }
  return 0;
}