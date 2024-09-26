#include <bits/stdc++.h>
#define MAX 112

char s[MAX];

int main(){
  int t, n;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    scanf(" %s", s);
    int sum = 0, group1 = 0, onlyone = 1;
    for(int i = 0; s[i]; i++){
      if(s[i] == '1') sum++;
      if(i > 0 && s[i-1] == '1' && s[i] == '0') group1 = 1;
      if(group1 && s[i] == '1') onlyone = 0;
    }
    if(sum & 1 || (sum == 2 && onlyone)) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}