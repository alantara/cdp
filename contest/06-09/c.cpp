#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 1123

int k, n;
int fr[MAX];
ii fri[MAX];

int main(){
  scanf("%d %d", &k, &n);
  for(int i = 0; i < n; i++){
    int s;
    scanf("%d", &s);
    fr[s]++;
  }
  for(int i = 1; i <= k; i++){
    fri[i-1] = ii(fr[i], i);
  }
  sort(fri, fri+k);
  int a[3] = {fri[0].first, fri[k/2].first, fri[k-1].first};
  int b[3] = {fri[0].second, fri[k/2].second, fri[k-1].second};
  if(a[2] - a[0] > 2) printf("*\n");
  else if(a[0] != a[1] && a[1] != a[2] && a[0] != a[2]) printf("-%d +%d\n", b[2], b[0]);
  else if(a[0] == a[1]) printf("-%d\n", b[2]);
  else if(a[1] == a[2]) printf("+%d\n", b[0]);
  return 0;
}