// #include <bits/stdc++.h>

// int main(void){
//   int tc;
//   scanf("%d", &tc);
//   while(tc--){
//     int n;
//     scanf("%d", &n);
//     int ans = -1, max = 0;
//     for(int i = 2; i <= n; i++){
//       int sum = 0;
//       for(int j = i; j <=  n; j+=i){
//         sum+=j;
//       }
//       if(sum > max){
//         max = sum;
//         ans = i;
//       }
//     }
//     printf("%d\n", ans);
//   }
//   return 0;
// }

#include <bits/stdc++.h>

int main(void){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    int n;
    scanf("%d", &n);
    if(n == 3){
      printf("3\n");
    }
    else{
      printf("2\n");
    }
  }
  return 0;
}