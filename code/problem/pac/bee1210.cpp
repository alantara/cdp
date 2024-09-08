#include <bits/stdc++.h>
using namespace std;
#define MAX 2123
#define INF 112345678

int n, l, m, p;
int c[MAX], v[MAX];

int s[MAX][MAX], path[MAX][MAX];
int st[MAX], stp;

int dp(int pr, int ag){
  if(s[pr][ag] != INF) return s[pr][ag];
  if(pr == n) return s[pr][ag] = 0;
  if(ag < m && dp(pr+1, ag+1) + c[ag] < s[pr][ag]){
    s[pr][ag] = dp(pr+1, ag+1) + c[ag];
    path[pr][ag] = 1;
  }
  if(ag > 0 && dp(pr, 0) + p - v[ag] <= s[pr][ag]){
    s[pr][ag] = dp(pr, 0) + p - v[ag];
    path[pr][ag] = 0;
  }
  return s[pr][ag];
}

void find(int pr, int ag){
  if(path[pr][ag] == -1) return;
  if(path[pr][ag] == 1){
    find(pr+1, ag+1);
  }
  if(path[pr][ag] == 0){
    st[stp++] = pr;
    find(pr, 0);
  }
}

int main(){
  while(scanf("%d %d %d %d", &n, &l, &m, &p) != EOF){
    for(int i = 0; i < m; i++) scanf("%d", &c[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &v[i]);
    stp = 0;
    for(int i = 0; i <= n; i++){
      st[i] = 0;
      for(int j = 0; j <= m; j++){
        s[i][j] = INF;
        path[i][j] = -1;
      }
    }
    printf("%d\n", dp(0, l));
    find(0, l);
    if(stp) for(int i = 0; i < stp; i++) printf("%s%d", i == 0 ? "": " ", st[i]+1);
    else printf("0");
    printf("\n");
  }
  return 0;
}