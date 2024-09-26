#include <bits/stdc++.h>
using namespace std;

int a, b;

int find(){
  int ans = 0;
  for(int i = 1; a <= b; i++){
    a = a + i;
    ans++;
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &a, &b);
    printf("%d\n", find());
  }
  return 0;
}