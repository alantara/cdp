#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> p;

int main(){
  scanf("%d %d", &n, &x);

  for(int i = 0; i < n; i++){
    int tmp;
    scanf("%d", &tmp);
    p.push_back(tmp);
  }

  sort(p.begin(), p.end());

  int l=0, r=n-1, s=0;
  while(l < r){
    if(p[l]+p[r] > x) s++, r--;
    else s++, l++, r--;
  }

  printf("%d", (l==r) ? s+1: s);

}