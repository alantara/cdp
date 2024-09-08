#include <bits/stdc++.h>
using namespace std;
#define MAX 1123456
#define pos(i) (i)>=0 ? 2*(i): 2*-(i)+1

int n, m;
int vis[MAX];

int bfs(int i){
  queue<int> q;
  vis[pos(i)] = 1;
  q.push(i);
  while(!q.empty()){
    int e = q.front(); q.pop();
    int p;
    if((p = pos(2*e)) < MAX && !vis[p]){
      vis[p] = vis[pos(e)] + 1;
      q.push(2*e);
    }
    if((p = pos(3*e)) < MAX && !vis[p]){
      vis[p] = vis[pos(e)] + 1;
      q.push(3*e);
    }
    if((p = pos(e/2)) < MAX && !vis[p]){
      vis[p] = vis[pos(e)] + 1;
      q.push(e/2);
    }
    if((p = pos(e/3)) < MAX && !vis[p]){
      vis[p] = vis[pos(e)] + 1;
      q.push(e/3);
    }
    if((p = pos(e+7)) < MAX && !vis[p]){
      vis[p] = vis[pos(e)] + 1;
      q.push(e+7);
    }
    if((p = pos(e-7)) < MAX && !vis[p]){
      vis[p] = vis[pos(e)] + 1;
      q.push(e-7);
    }
  }
  return vis[pos(m)] - 1;
}

int main(){
  scanf("%d %d", &n, &m);
  printf("%d\n", bfs(n));
  return 0;
}