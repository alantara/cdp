#include <bits/stdc++.h>
using namespace std;

int o, d, k;
int vis[112345];

int bfs(int u, int c){
  queue<int> q;
  vis[u] = 0;
  q.push(u);
  while(!q.empty()){
    int i = q.front(); q.pop();
    if(i + 1 <= 100000 && vis[i+1] == -1) {vis[i+1] = vis[i] + 1; q.push(i+1);}
    if(i - 1 >= 0 && vis[i-1] == -1) {vis[i-1] = vis[i] + 1; q.push(i-1);}
    if(i % 2 == 0 && vis[i/2] == -1) {vis[i/2] = vis[i] + 1; q.push(i/2);}
    if(i*2 <= 100000 && vis[i*2] == -1) {vis[i*2] = vis[i] + 1; q.push(i*2);}
    if(i*3 <= 100000 && vis[i*3] == -1) {vis[i*3] = vis[i] + 1; q.push(i*3);}
  }
  return vis[c];
}

int main(){
  while(scanf("%d %d %d", &o, &d, &k), o){
    for(int i = 0; i < 112345; i++){
      vis[i] = -1;
    }
    for(int i = 0; i < k; i++){
      int c;
      scanf("%d", &c);
      vis[c] = -2;
    }
    printf("%d\n", bfs(o, d));
  }
  return 0;
}