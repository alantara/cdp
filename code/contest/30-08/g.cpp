#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1.1e5;

int n, pbig[MAX_N], psum[MAX_N], a[MAX_N], val[4*MAX_N];
ll t[4*MAX_N], lazy[4*MAX_N];

void sieve() {
  fill(pbig, pbig+MAX_N, 0);
  fill(psum, psum+MAX_N, 0);
  for(int i = 2; i < MAX_N; ++i) {
    if(psum[i] != 0) continue;
    for(int j = i; j < MAX_N; j += i) {
      pbig[j] = i;
      int tmp = j;
      while(tmp % i == 0) tmp /= i, psum[j] += i;
    }
  }
}

ll build_t(int u = 1, int l = 0, int r = n) {
  lazy[u] = 0;
  if(r-l == 1) return t[u] = psum[val[u] = a[l]];
  int m = (l+r)/2;
  return t[u] = build_t(2*u, l, m) + build_t(2*u + 1, m, r);
}

ll remove_t(int i, int u = 1, int l = 0, int r = n) {
  if(l > i || r <= i) return t[u];
  if(l == i && r == i+1) {
    val[u] = val[u] == 1 ? 1 : val[u]/pbig[val[u]];
    return t[u] = psum[val[u]];
  }
  int m = (l+r)/2;
  if(lazy[u] != 0) {
    lazy[2*u] = lazy[u], lazy[2*u + 1] = lazy[u];
    if(m-l == 1) val[2*u] = lazy[u];
    if(r-m == 1) val[2*u + 1] = lazy[u];
    t[2*u] = (ll)(m-l)*psum[lazy[u]], t[2*u + 1] = (ll)(r-m)*psum[lazy[u]];
    lazy[u] = 0;
  }
  return t[u] = remove_t(i, 2*u, l, m) + remove_t(i, 2*u + 1, m, r);
}

ll assign_t(int i, int j, int x, int u = 1, int l = 0, int r = n) {
  if(l >= j || r <= i) return t[u];
  if(l >= i && r <= j) {
    lazy[u] = x;
    if(r-l == 1) val[u] = x;
    return t[u] = (ll)(r-l)*psum[x];
  }
  int m = (l+r)/2;
  if(lazy[u] != 0) {
    lazy[2*u] = lazy[u], lazy[2*u + 1] = lazy[u];
    if(m-l == 1) val[2*u] = lazy[u];
    if(r-m == 1) val[2*u + 1] = lazy[u];
    t[2*u] = (ll)(m-l)*psum[lazy[u]], t[2*u + 1] = (ll)(r-m)*psum[lazy[u]];
    lazy[u] = 0;
  }
  return t[u] = assign_t(i, j, x, 2*u, l, m) + assign_t(i, j, x, 2*u + 1, m, r);
}

ll sum_t(int i, int j, int u = 1, int l = 0, int r = n) {
  if(l >= j || r <= i) return 0;
  if(l >= i && r <= j) return t[u];
  int m = (l+r)/2;
  if(lazy[u] != 0) {
    lazy[2*u] = lazy[u], lazy[2*u + 1] = lazy[u];
    if(m-l == 1) val[2*u] = lazy[u];
    if(r-m == 1) val[2*u + 1] = lazy[u];
    t[2*u] = (ll)(m-l)*psum[lazy[u]], t[2*u + 1] = (ll)(r-m)*psum[lazy[u]];
    lazy[u] = 0;
  }
  return sum_t(i, j, 2*u, l, m) + sum_t(i, j, 2*u + 1, m, r);
}

int main() {
  sieve();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
  build_t();
  int q;
  scanf("%d", &q);
  while(q--) {
    int type, i, l, r, x;
    scanf("%d", &type);
    switch(type) {
      case 1:
        scanf("%d", &i);
        --i;
        remove_t(i);
        break;
      case 2:
        scanf("%d %d", &l, &r);
        --l;
        printf("%lld\n", sum_t(l, r));
        break;
      case 3:
        scanf("%d %d %d", &l, &r, &x);
        --l;
        assign_t(l, r, x);
    }
  }
  return 0;
}
