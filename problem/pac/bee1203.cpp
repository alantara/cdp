#include <bits/stdc++.h>
using namespace std;
#define MAX 112
#define PMAX 11234

int s[MAX][PMAX];
int r, k, u, v;
vector<int> adj[MAX];

int dp(int reg, int sum){
  if(s[reg][sum] != -1) return s[reg][sum];
  if(reg == r) return sum == k;
  int bridges = 0;
  for(auto v: adj[reg]) bridges++;
  return s[reg][sum] = dp(reg+1, sum) || dp(reg+1, sum+bridges);
}

int main(){
  while(scanf("%d %d", &r, &k) != EOF){
    for(int i = 0; i < MAX; i++){
      adj[i].clear();
      for(int j = 0; j < PMAX; j++) s[i][j] = -1;
    }
    for(int i = 0; i < k; i++){
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);      
    }
    printf("%c\n", dp(0, 0) ? 'S': 'N');
  }
  return 0;
}