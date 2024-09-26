#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    int k;
    scanf("%d", &k);
    ll ans = 0;
    for(int i = 0; i < k; ++i) {
      int a;
      scanf("%d", &a);
      ans += 1ll<<(a-1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
