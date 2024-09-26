#include <bits/stdc++.h>

int main(void) {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", k >= n-1 ? 1 : n);
  }
  return 0;
}
