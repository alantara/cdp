#include <bits/stdc++.h>

using namespace std;

const int LEN_S = 2.1e5;

char s[LEN_S];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d %s", &n, s);
    int ans = n;
    for(int d = 1; d*d <= n; ++d) {
      if(n % d != 0) continue;
      int diff = 0;
      for(int i = d; i < n && diff < 2; ++i)
        diff += s[i] != s[i % d];
      if(diff < 2) ans = min(ans, d);
      diff = 0;
      d = n / d;
      for(int i = d; i < n && diff < 2; ++i)
        diff += s[i] != s[i % d];
      if(diff < 2) ans = min(ans, d);
      d = n / d;
    }
    reverse(s, s+n);
    for(int d = 1; d*d <= n; ++d) {
      if(n % d != 0) continue;
      int diff = 0;
      for(int i = d; i < n && diff < 2; ++i)
        diff += s[i] != s[i % d];
      if(diff < 2) ans = min(ans, d);
      diff = 0;
      d = n / d;
      for(int i = d; i < n && diff < 2; ++i)
        diff += s[i] != s[i % d];
      if(diff < 2) ans = min(ans, d);
      d = n / d;
    }
    printf("%d\n", ans);
  }
  return 0;
}
