#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int is_perf_sq(int n) {
  int sqrtn = floor(sqrt(n));
  return n == sqrtn*sqrtn;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    ll sum = 1;
    for(int i = 2; i <= n; ++i) {
      int cnt = 0;
      while(is_perf_sq(n)) n = sqrt(n), ++cnt;
      sum += cnt == 0 ? n : ((ll)i*i <= n ? 0 : cnt);
    }
    printf("%lld\n", sum);
  }
  return 0;
}
