#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, vis[700][700], lab[700][700];
char buf[400];

void dfs(int i, int j){
  stack<int> s;
  s.push(i*2*(n+1) + j);
  while(!s.empty()){
    int x = s.top(); s.pop();
    i = x / (2*(n+1));
    j = x % (2*(n+1));
    if(vis[i][j]) continue;
    vis[i][j] = 1;
    if(lab[i][j] & 1) s.push((i-1)*2*(n+1) + j);
    if(lab[i][j] & 2) s.push((i)*2*(n+1) + j+1);
    if(lab[i][j] & 4) s.push((i+1)*2*(n+1) + j);
    if(lab[i][j] & 8) s.push((i)*2*(n+1) + j-1);
  }
}

int main(){
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < 2*n; i++){
      for(int j = 0; j < 2*n+1; j++){
        vis[i][j] = 0;
        lab[i][j] = 15;
        if(i == 0) lab[i][j] &= ~1;
        if(j == 2*n) lab[i][j] &= ~2;
        if(i == 2*n - 1) lab[i][j] &= ~4;
        if(j == 0) lab[i][j] &= ~8;
      }
    }
    for(int i = 1; i <= 2*n-1; i++){
      scanf(" %s", buf);
      for(int j = 1; j <= n; j++){  
        int r = i;
        int c = 2*j;
        if(r % 2) c--;
        switch(buf[j-1]){
          case 'H':
            lab[r-1][c-1] &= ~4;
            lab[r-1][c] &= ~4;
            lab[r][c-1] &= ~1;
            lab[r][c] &= ~1;
          break;
          case 'V':
            lab[r-1][c-1] &= ~2;
            lab[r][c-1] &= ~2;
            lab[r-1][c] &= ~8;
            lab[r][c] &= ~8;
          break;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < 2*n; i++){
      for(int j = 0; j < 2*n+1; j++){
        if(vis[i][j] == 0){
          dfs(i, j);
          ans++;
        }
      }
    }
    printf("%d\n", ans-1);
  }
  return 0;
}