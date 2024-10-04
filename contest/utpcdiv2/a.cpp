#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define INF 11234123412341234

int n;
vector<ii> points;
ii s;

ll dist(ii a, ii b){
  ll dx = abs(a.first - b.first), dy = abs(a.second - b.second);
  return dx*dx + dy*dy;
}

int main(){
  int a, b;
  scanf("%d", &n);
  scanf("%d %d", &a, &b);
  s = ii(a, b);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &a, &b);
    points.push_back(ii(a, b));
  }
  ll dmin = INF;
  ii pmin;
  for(auto &p: points){
    if(dmin >= dist(s, p) ){
      if(dist(s, p) == dmin){
        ii srt[2] = {pmin, p};
        sort(srt, srt + 2);
        pmin = srt[0];
      }
      else{
        pmin = p;
      }
      dmin = dist(s, p);
    }
  }
  printf("%d %d\n", pmin.first, pmin.second);
  return 0;
}