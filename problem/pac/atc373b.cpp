#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 112

char buf[MAX];
ii srt[MAX];

int main(){
  scanf("%s", buf);
  int len = 0;
  for(int i = 0; buf[i]; i++){
    srt[i] = ii(buf[i]-'A', i);
    len++;
  }
  sort(srt, srt+len);
  int ans = 0;
  for(int i = 1; i < len; i++){
    ans += abs(srt[i].second - srt[i-1].second);
  }
  printf("%d\n", ans);
  return 0;
}