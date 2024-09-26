#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> a, b;

int main(){
  
  scanf("%d %d %d", &n, &m, &k);

  for(int i = 0; i < n; i++){
    int tmp;
    scanf("%d", &tmp);
    a.push_back(tmp);
  }
  for(int i = 0; i < m; i++){
    int tmp;
    scanf("%d", &tmp);
    b.push_back(tmp);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int s=0;

  for(int i = 0, j = 0; i < n; i++){
    if(b[j] > a[i]+k) continue;
    
    while(j < m && b[j] < a[i]-k) j++;

    if(j >= m) break;
    if(b[j] <= a[i]+k) s++, j++;
  }

  printf("%d", s);

  return 0;
}