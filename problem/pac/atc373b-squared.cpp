#include <bits/stdc++.h>
using namespace std;
#define MAX 112

char buf[MAX];

int main(){
  scanf("%s", buf);
  int ans = 0, letter = 0, lastletteri = 0;
  for(int i = 0; i < 26; i++){
    int j;
    for(j = 0; buf[j] != letter + 'A'; j++);
    if(i != 0) ans += abs(j - lastletteri);
    letter++;
    lastletteri = j;
  }
  printf("%d\n", ans);
  return 0;
}