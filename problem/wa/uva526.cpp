#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> si;
typedef tuple<int, int, char, string> iics;
#define MAX 212
#define INF 112341234

int n, m;
char s1[MAX], s2[MAX];
string str1, str2;
map<string, int> memo;
map<si, iics> path;

int dp(string s, int b){
  if(memo[s]) return memo[s];
  printf("%s %d\n", s.c_str(), b);

  if(s == str2) return 0;
  int stlen = (int)s.size();
  string i = s; i.insert(b, 1, s2[b]);
  string d = s; d.erase(b, 1);
  string r = s; r[b] = s2[b];
  int ans = INF;
  if(b < m && ans > dp(i, b+1) + 1){
    ans = dp(i, b+1) + 1;
    path[si(s, b)] = iics(1, b, s2[b], i);
  }
  if(stlen > b+1 && ans > dp(d, b) + 1){
    ans = dp(d, b) + 1;
    path[si(s, b)] = iics(2, b, s2[b], d);    
  }
  if(b < stlen && b < m && ans > dp(r, b+1) + (s[b] != s2[b])){
    ans = dp(r, b+1) + (s[b] != s2[b]);
    path[si(s, b)] = iics((s[b] != s2[b]) ? 3: 0, b, s2[b], r);    
  }
  return memo[s] = ans;
}

int main(){
  int first = 1;
  while(scanf(" %s %s", s1, s2) != EOF){
    if(!first) printf("\n"); 
    first = 0;
    memo.clear(); path.clear();
    str1 = string(s1), str2 = string(s2);
    n = (int)str1.size(); m = (int)str2.size();
    printf("%d\n", dp(str1, 0));
    int cnt = 1, b = 0;
    string u = str1;
    while(u != str2){
      int o, s;
      char c;
      string nstr;
      auto it = path[si(u, b)];
      tie(o, s, c, nstr) = it;
      if(o != 2) b++;
      if(o == 2) printf("%d Delete %d\n", cnt++, s+1);
      else if(o != 0) printf("%d %s %d,%c\n", cnt++, o == 1 ? "Insert": "Replace", s+1, c);
      u = nstr;
    }
  }
  return 0;
}