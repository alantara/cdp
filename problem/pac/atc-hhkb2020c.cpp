#include <bits/stdc++.h>
using namespace std;
#define MAX 212345

int n, a;
int fr[MAX], ptr;

int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%d", &a);
    fr[a]++;
    while(fr[ptr]) ptr++;
    printf("%d\n", ptr);
  }
  return 0;
}