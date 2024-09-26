#include <bits/stdc++.h>

int n, k, f[123];
char s[1123];

int main(){
  scanf("%d %d %s", &n, &k, s);
  for(int i = 0; i < n; i++){
    f[s[i] - 'a']++;
  }
  int odd = 0;
  for(int i = 0; i < 26; i++){
    k -= 2 * (f[i] / 2);
    f[i] -= 2 * (f[i] / 2);
    if(f[i]) odd++;
  }
  int ans = 0;
  while(k > 1) {
    ans += 1;
    k -= 2;
  }
  printf("%d\n", ans);
  return 0;
}