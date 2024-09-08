#include <bits/stdc++.h>
using namespace std;


int l, w, h, u, v, z;
vector<int> bb, sb;
int ans = 0;

int solve (){
  int num = 1;
  for(int i = 0; i < 3; i++){
    if(bb[i] < sb[i]){
      return 0;
    }
    num *= (bb[i]/sb[i]);
  }
  return num;
}

int main(){
  int tmp;
  for(int i = 0; i < 3; i++){
    cin >> tmp;
    bb.push_back(tmp);
  }

  for(int i = 0; i < 3; i++){
    cin >> tmp;
    sb.push_back(tmp);
  }
  sort(sb.begin(), sb.end());
  ans = max(ans,solve());
  while(next_permutation(sb.begin(),sb.end())){
    ans = max(ans,solve());
  }
  printf("%d\n", ans);
  
  return 0;
}