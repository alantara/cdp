#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
 
int n, k;
char buf[MAX];
int p[MAX], ptr;
 
int main(){
  scanf("%d %d", &n, &k);
  scanf("%s", buf);
  int ans = 0;
  int sti = 0, nk = 0;
  for(int i = 0; buf[i]; i++){
    int d = buf[i] - '0';
    if(d == 2){
      if(nk < k) nk++;
      else{
        ans = max(ans, i-1 - sti + 1);
        sti = p[ptr] + 1;
      }
      p[ptr] = i;
      ptr = (ptr+1)%k;
    }
    if(!buf[i+1]) ans = max(ans, i - sti + 1);
  }
  printf("%d\n", ans);
  return 0;
}
