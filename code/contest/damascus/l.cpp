#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2.1e5;

int a[MAX_N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a+n);
    int i_med = (n-1)/2;
    int ans = n & 1 ? a[i_med] == a[i_med-1]
                    : a[i_med] == a[i_med+1]
                      || (n > 2 && a[i_med] == a[i_med-1]);
    printf("%s\n", ans ? "YES" : "NO");
  }
}
