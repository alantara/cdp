#include <bits/stdc++.h>
using namespace std;
#define MAX 1123

char buf[MAX];
int fr[112];

int main(){
  scanf(" %s", buf);
  for(int i = 0; buf[i]; i++){
    fr[buf[i]-'A']++;
  }
  printf("%d\n", min(fr['T'-'A'], min(fr['P'-'A'], fr[0] + fr['U'-'A'])));
  return 0;
}