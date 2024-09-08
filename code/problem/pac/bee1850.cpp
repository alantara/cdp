#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#define MAX 112

char buf[MAX], l[MAX][MAX];
int n, m, dist[MAX][MAX][128];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(int u, int v){
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      for(int k = 0; k < 128; k++){
        dist[i][j][k] = -1;
      }
    }
  }
  queue<iii> q;
  dist[u][v][0] = 0;
  q.push(iii(ii(u, v), 0));
  while(!q.empty()){
    int i, j, w;
    ii ij;
    tie(ij, w) = q.front(); tie(i, j) = ij; q.pop();
    if(l[i][j] == '*') return dist[i][j][w];
    for(int k = 0; k < 4; k++){
      int di = i + dr[k], dj = j + dc[k];
      char c;
      if(di >= 0 && di < n && dj >= 0 && dj < m &&
        (c = l[di][dj]) != '#' &&
        (!(c >= 'A' && c <= 'G') || w & (1<<(c-'A')))){
          int x = (c >= 'a' && c <= 'g') ? w | (1<<(c-'a')): w;
          if(dist[di][dj][x] == -1){
            dist[di][dj][x] = dist[i][j][w] + 1;
            q.push(iii(ii(di, dj), x));
          }
        }
    }
  }
  return -1;
}

int main(){
  int i = 0, j = 0;
  for(n = 0; scanf("%s", buf) != EOF; n++){
    for(m = 0; buf[m] != '\0'; m++){
      l[n][m] = buf[m];
      if(buf[m] == '@'){
        i = n;
        j = m;
      }
    }
  }
  int ans = bfs(i, j);
  if(ans != -1) printf("%d\n", ans);
  else printf("--\n");
  return 0;
}