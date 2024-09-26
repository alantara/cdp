#include <bits/stdc++.h>

#define MAX 1012345
char c[MAX], s[MAX];
int a[26];
int n;

int main(){
  scanf("%s", c);
  memset(a, 0, 26);

  for(int i = 0; c[i] != '\0'; i++){
    a[c[i]-'A'] += 1;
    n++;
  }

  int l = 0;
  for(int i = 0; i<26; i++){
    while(a[i] != 0 && a[i] != 1){
      s[l] = 'A' + i;
      s[n-l-1] = 'A' + i;
      l++;
      a[i]-=2;
    }
  }

  int r = 0, p;
  for(int i = 0; i < 26; i++){
    if(a[i] == 1){
      r++;
      p = i;
    }
  }

  if(r == 0){
    s[n] = '\0';
    printf("%s", s);
  }
  else if(r == 1){
    s[l] = 'A' + p;
    s[n] = '\0';
    printf("%s", s);
  }
  else{
    printf("NO SOLUTION");
  }
}
