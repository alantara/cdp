#include <bits/stdc++.h>
using namespace std;
#define MAX 1123456

int pri[MAX];
int n;
vector<int> q;

void crivo(){
  for(int i = 0; i < MAX; i++){
    pri[i] = 1;
  }
  pri[0] = 0;
  pri[1] = 0;
  for(int i = 0; i < MAX; i++){
    if(!pri[i]) continue;
    for(int j = i+i; j < MAX; j += i){
      pri[j] = 0;
    }
  }
}

int main(){
  scanf("%d", &n);
  crivo();
  int ans = 0;
  for(int i = n; i >= 1; i--){
    if(pri[i] && n % i == 0){
      ans++;
      q.push_back(i);
    }
  }
  printf("%d\n", ans);
  for(auto u: q){
    printf("%d %d\n", 1, n/u);
  }
  return 0;
}