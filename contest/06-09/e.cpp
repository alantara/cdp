#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 1123

int n, strl;
char s[MAX];
int m[MAX][MAX];
ii p[MAX][MAX];

int dp(int dg, int a){
  if(m[dg][a] != n) return m[dg][a];
  if(dg == strl) return m[dg][a] = a;
  if(s[dg] != '?'){
    p[dg][a] = ii((10*a + s[dg] - '0') % n, s[dg] - '0');
    return m[dg][a] = dp(dg+1, (10*a + s[dg] - '0') % n);
  }
  int low = n;
  for(int i = 0; i < 10; i++){
    if(dg == 0 && i == 0) continue;
    if(low > dp(dg+1, (10*a + i) % n)){
      low = dp(dg+1, (10*a + i) % n);
      p[dg][a] = ii((10*a + i) % n, i);
    }
  } 
  return m[dg][a] = low;
}

void find(int dg, int a){
  if(dg == strl || p[dg][a].first == -1) return;
  printf("%d", p[dg][a].second);
  find(dg+1, p[dg][a].first);
}

int main(){
  scanf("%s %d", s, &n);
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++) m[i][j] = n, p[i][j] = ii(-1, -1);
  }
  for(strl = 0; s[strl] != '\0'; strl++);
  if(dp(0, 0) != 0) printf("*\n");
  else{
    find(0, 0);
    printf("\n");
  }
  return 0;
}