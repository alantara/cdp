#include <bits/stdc++.h>
using namespace std;
#define MAX 112
#define INF 112345678

int dist[MAX][MAX];

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};

int cord(int u, int v){
  return u*8 + v;
}

void fwarshall(){
  for(int k = 0; k < 64; k++)
    for(int i = 0; i < 64; i++)
      for(int j = 0; j < 64; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}

int main(){
  char c1, c2;
  int u1, v1, u2, v2;
  for(int i = 0; i < 64; i++)
    for(int j = 0; j < 64; j++)
      dist[i][j] = INF;
  for(int i = 0; i < 64; i++){
    u1 = i/8; v1 = i%8;
    dist[i][i] = 0;
    for(int d = 0; d < 8; d++){
      int du = u1 + dr[d], dv = v1 + dc[d];
      if(du >= 0 && du < 8 && dv >= 0 && dv < 8) dist[cord(u1, v1)][cord(du, dv)] = 1;
    }
  }
  fwarshall();
  while(scanf(" %c%d %c%d", &c1, &v1, &c2, &v2) != EOF){
    u1 = c1-'a'; u2 = c2-'a'; v1--; v2--;
    printf("To get from %c%d to %c%d takes %d knight moves.\n",
     c1, v1+1, c2, v2+1, dist[cord(u1, v1)][cord(u2, v2)]);
  }
  return 0;
}