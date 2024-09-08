#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1.1e6;

int sumd[MAX_N];

void sieve() {
  fill(sumd, sumd+MAX_N, 1);
  for(int i = 2; i < MAX_N; ++i) {
    if(sumd[i] != 1) continue;
    for(int j = i; j < MAX_N; j += i) {
      int tmp = j, p = 1;
      while(tmp % i == 0) tmp /= i, p *= i;
      sumd[j] = (ll)sumd[j]*(p*i-1)/(i-1);
    }
  }
  sumd[0] = 1.1e6-1;
  for(int i = 1; i < MAX_N; ++i) sumd[i] -= i;
}

int main() {
  sieve();
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    printf("%d ", a);
    if(sumd[a] == a) {
      printf("perfecto\n");
    } else if(sumd[sumd[a]] == a) {
      printf("romantico");
      if(sumd[a] > a)
        printf(" abundante");
      printf("\n");
    } else if(sumd[a] > a) {
      printf("abundante\n");
    } else {
      printf("complicado\n");
    }
  }
}
