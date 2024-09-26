#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1123456

int n, m, k;
int a[MAX];

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; k >= 0; i++){
      int b = min(m, k);
      ans += b * (a[i] + (ll)i * m);
      k -= m;
    }
    printf("%lld\n", ans);
  }
  return 0;
}