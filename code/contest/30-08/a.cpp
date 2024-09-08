#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll a, b, c, l ,r;
ll z1, z2;

void get_zeros(){
  z1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
  z2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
}

ll solve(ll l, ll r){
  return ((2*a*r*r*r) + (3*b*r*r) + (6*c*r) - (2*a*l*l*l) - (3*b*l*l) - (6*c*l));
}

int main(){
  scanf("%lld", &n);
  while(n--){
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &l, &r);

    get_zeros();

    ll v[4] = {l,r,z1,z2};
    sort(v, v+4);
    ll tmp = 0;

    for(int i = 0; i < 3 && v[i+1] <= r; i++){
      if(v[i]<l){
        continue;
      }
      tmp += abs(solve(v[i], v[i+1]));
    }

    ll den = 6;
    if(tmp%2 == 0){
      tmp /= 2;
      den /= 2;
    }
    if(tmp%3 == 0){
      tmp /= 3;
      den /= 3;
    }
    printf("%lld/%lld\n", tmp, den);

  }

  return 0;
}