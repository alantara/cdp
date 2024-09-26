#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 212345
#define MOD 1000000007
int n, a[MAX];

ll binexp(ll a, ll p, ll mod){
  if(p == 0) return 1;
  if(p & 1) return (a * binexp(a, p-1, mod)) % mod;
  ll exp = binexp(a, p/2, mod);
  return (exp * exp) % mod;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    ll sum = 0;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
    ll num = 0, den = ((ll)n * (n-1)) % MOD;
    for(int i = 0; i < n; i++){
      num += (a[i] * ((sum-a[i]) % MOD)) % MOD;
      num %= MOD;
    }
    printf("%lld\n", (num * binexp(den, MOD-2, MOD)) % MOD);
  }
  return 0;
}