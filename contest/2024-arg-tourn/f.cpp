#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
  int ans = 0, tmp, cnt = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &tmp);
    if(tmp == 0){
      ans--;
      cnt = 0;
    } else{
      cnt++;
      ans++;
      if(cnt >= 3) ans++;
    }
  } 
  printf("%d\n", ans);
  return 0;
}