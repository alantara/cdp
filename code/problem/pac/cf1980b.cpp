#include <bits/stdc++.h>

using namespace std;

int a[112];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, f, k;
    scanf("%d %d %d", &n, &f, &k);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int fav = a[f-1];
    sort(a, a+n, greater<int>());
    printf("%s\n", k == n || a[k] < fav ? "YES"
                   : (a[k] == fav && a[k-1] == fav ? "MAYBE" : "NO"));
  }
  return 0;
}
