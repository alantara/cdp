#include <bits/stdc++.h>
using namespace std;

char buf[30];

int main(){
  scanf("%s", buf);
  int ans = 0, letter = 0, li = 0;
  for(letter = 0; letter < 26; letter++){
    int j;
    for(j = 0; buf[j] != letter + 'A'; j++);
    if(letter) ans += abs(j - li);
    li = j;
  }
  printf("%d\n", ans);
  return 0;
}