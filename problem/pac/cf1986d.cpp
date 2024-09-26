#include <bits/stdc++.h>
using namespace std;

int n, dig[50], nums[50];
char buf[50];

int main (){
  int t;  
  scanf("%d", &t);
  while (t--){
    scanf("%d %s", &n, buf);
    for(int i = 0; i < n; ++i) dig[i] = buf[i] - '0';
    nums[0] = 10 * dig[0] + dig[1];
    copy(dig+2, dig+n, nums+1);
    int zero = 0, min_sum = 1e9;
    for(int i = 0; i < n-1 && !zero; ++i) {
      int sum = 0;
      int ones = 1;
      for(int j = 0; j < n-1 && !zero; ++j) {
        if(nums[j] == 0) {
          printf("0\n");
          zero = 1;
        } else if(nums[j] != 1) {
          sum += nums[j];
        }
        ones &= nums[j] == 1;
      }
      if(ones) sum = 1;
      min_sum = min(min_sum, sum);
      nums[i] = dig[i];
      nums[i+1] += 10*dig[i+1];
    }
    if(!zero) printf("%d\n", min_sum);

    // if(n == 2) {
    //   printf("%d\n", (buf[0]-'0') * 10 + (buf[1] -'0'));
    //   continue;
    // }
    // if(n == 3 && buf[1] == '0'){
    //   int p = buf[0] - '0';
    //   int q = buf[2] - '0';
    //   if(p == 1 || q == 1){
    //     printf("%d\n", p*q);
    //   }else{
    //     printf("%d\n", p+q);
    //   }
    //   continue;
    // }
    // int zero = 0;
    // for(int i = 0; i < n; i++){
    //   if(buf[i] == '0'){
    //     zero++;
    //   }
    // }
    // if(zero){
    //   printf("0\n");
    //   continue;
    // }
    // int min = 100, minI = -1;
    // for(int i = 0; i < n-1; i++){
    //   int d = buf[i] - '0';
    //   if(d <= min){
    //     min = d;
    //     minI = i;
    //   }
    // }
    // int sum = 0;
    // for (int i = 0; i < n; i++){
    //   if(i == minI){ sum += (buf[i] - '0') * 10;}
    //   else {
    //     if(buf[i] == '1')  continue;
    //     else sum += buf[i] -'0';
    //   }
    // }
    // if (buf[n-1] == '1' &&  buf[n-2] == '1') sum++;
    // printf("%d\n", sum);
  }
  return 0;
}
