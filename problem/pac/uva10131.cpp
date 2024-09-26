#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define MAX 1123

int w, s, n;
iii e[MAX];
int q[MAX], p[MAX];

int main(){
  fill(q, q+MAX, 1);
  fill(p, p+MAX, -1);
  for(n = 0; scanf("%d %d", &w, &s) != EOF; n++){
    e[n] = iii(w, 10000 - s, n+1);
  }
  sort(e, e+n);
  for(int i = n-1; i >= 0; i--){
    for(int j = i+1; j < n; j++){
      int w1, s1, i1, w2, s2, i2;
      tie(w1, s1, i1) = e[i]; tie(w2, s2, i2) = e[j];
      if(w2 > w1 && s2 > s1 && q[i] < q[j] + 1){
        q[i] = q[j] + 1;
        p[i] = j;
      }
    }
  }
  int u = 0, m = 0;
  for(int i = 0; i < n; i++){
    if(m < q[i]){
      m = q[i]; u = i;
    }
  }
  printf("%d\n", m);
  while(u != -1){
    int i;
    tie(w, s, i) = e[u];
    printf("%d\n", i);
    u = p[u];
  }
  return 0;
}