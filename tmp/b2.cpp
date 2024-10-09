#include <bits/stdc++.h>
using namespace std;

char buf[30];
int id[30];

int main(){
  scanf("%s", buf);
  for(int i = 0; i < 26; i++){
    id[buf[i]-'A'] = i;
  }
  int ans = 0;
  for(int i = 1; i < 26; i++){
    ans += abs(id[i] - id[i-1]);
  }
  printf("%d\n", ans);
  return 0;
}