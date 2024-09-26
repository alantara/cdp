#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int n;
char s[MAX], t[MAX];

int main(){
  scanf("%d %s %s", &n, s, t);
  string sstr(s), tstr(t);
  sstr += sstr; tstr += tstr;
  int ans = 0;
  for(int i = 0; i < n; i++){
    string ssub = sstr.substr(i, n), tsub = tstr.substr(n-i-1, n);
    if(tsub >= ssub) ans++;
  }
  printf("%d\n", ans);
  return 0;
}