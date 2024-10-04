#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 112

int n;
ii p[MAX];

double hip(ii a, ii b){
  int dx = a.first - b.first, dy = a.second - b.second;
  return sqrt(dx * dx + dy * dy);
}

int main(){
  int c, a, b;
  scanf("%d", &c);
  while(c--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d %d", &a, &b);
      p[i] = ii(a, b);
    }
    sort(p, p+n);
    double ans = 0, ymax = p[n-1].second;
    for(int i = n-2; i >= 0; i--){
      if(p[i].second > ymax){
        ans += hip(p[i], p[i+1]) * (p[i].second - ymax) / (p[i].second - p[i+1].second);
        ymax = p[i].second;
      }
    }
    printf("%.2f\n", ans);
  }
  return 0;
}