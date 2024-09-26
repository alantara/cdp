#include <bits/stdc++.h>
using namespace std;
#define MAX 212345

int n;
char s[MAX];

int sqm(){
  int rn = sqrt(n);
  if(rn * rn != n) return 0;
  int ans = 1;
  for(int i = 0; i < rn; i++){
    for(int j = 0; j < rn; j++){
      int c = s[i * rn + j] - '0';
      if(i == 0 || i == rn-1) ans &= c;
      else if(j == 0 || j == rn-1) ans &= c;
      else ans &= !c;
    }
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %s", &n, s);
    printf("%s\n", sqm() ? "YES": "NO");
  }
  return 0;
}