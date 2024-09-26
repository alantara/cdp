  #include <bits/stdc++.h>

  int t, k, n;

  int main(void){
    scanf("%d", &t);
    while(t--){
      scanf("%d %d", &n, &k);
      if(k > 3) { printf("%d\n", n); continue; }
      int max = 0, r = 0;
      for(int i = 0; i <= k; i++){
        int amt = n-i;  
        if(amt % 3 != 0 && amt % 2 != 0){
          max = n;
          r = 0;
          break;
        }
        if(amt%3 == 0 && max < amt/3){
          max = amt/3;
          r = i;
        }
        else if(amt % 2 == 0 && max < amt/2){
          max = amt/2;
          r = i;
        }
      }
      printf("%d\n", max + r);  
    }
    return 0;
  }