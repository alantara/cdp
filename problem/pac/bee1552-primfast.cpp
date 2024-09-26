#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;

#define MAX 1123
#define INF 112345678

int n;
ii v[MAX];
vector<id> adj[MAX];
double d[MAX];
int ok[MAX];

double primfast(){
  double ans = 0;
  for(int i = 0; i < n; i++){
    d[i] = INF;
    ok[i] = 0;
  }
  int i = 0;
  d[i] = 0;
  while(i >= 0){
    ok[i] = 1;
    ans += d[i];
    for(auto &[v, w]: adj[i]){
      if(d[v] > w){
        d[v] = w;
      }
    }
    double min = INF; 
    int minI = -1;
    for(int i = 0; i < n; i++){
      if(!ok[i] && min > d[i]){
        min = d[i];
        minI = i;
      }
    }
    i = minI;
  }
  return ans;
}

double dist(int i, int j){
  int x, y, z, w;
  tie(x, y) = v[i]; tie(z, w) = v[j];
  int dx = x-z, dy = y-w;
  return sqrt(dx * dx + dy * dy);
}

int main(){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    for(int i = 0; i < MAX; i++){
      adj[i].clear();
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      int x, y;
      scanf("%d %d", &x, &y);
      v[i] = ii(x, y);
      for(int j = 0; j < i; j++){
        adj[i].push_back(id(j, dist(i, j)));
        adj[j].push_back(id(i, dist(i, j)));
      }
    }
    printf("%.2f\n", primfast()/100);
  }
  return 0;
}