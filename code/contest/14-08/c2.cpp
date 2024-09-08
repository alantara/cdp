#include <bits/stdc++.h>
using namespace std;

int b[3], c[3];
int v[3];

int find(int i){
  int ans = 0;
  if(i == 3) return 1;
  for(int j = 0; j < 3; j++){
    if(v[j] == 0){
      v[j] = 1;
      ans = max(ans, b[i]/c[j] * find(i+1));
      v[j] = 0;
    }
  }
  return ans;
}

int main(){
  scanf("%d %d %d %d %d %d", &b[0], &b[1], &b[2], &c[0], &c[1], &c[2]);
  printf("%d\n", find(0));
}