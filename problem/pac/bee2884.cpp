#include <bits/stdc++.h>
using namespace std;
#define MAX 1123

int n, m;
int lm[MAX];
vector<int> adj[MAX];

int main(){
  int l, k, a;
  scanf("%d %d", &n, &m);
  scanf("%d", &l);
  for(int i = 0; i < l; i++){
    scanf("%d", &a); a--;
    lm[a] = 1;
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &k);
    for(int j = 0; j < k; j++){
      scanf("%d", &a); a--;
      adj[i].push_back(a);
    }
  }
  int ans = -1;
  for(int i = 0; i < 2*n; i++){
    int ind = i % n;
    for(auto b: adj[ind]){
      if(lm[b]){
        l--;
        lm[b] = 0;
      }
      else{
        l++;
        lm[b] = 1;
      }
    }
    if(!l){
      ans = i + 1;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}