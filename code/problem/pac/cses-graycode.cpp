#include <bits/stdc++.h>

#define MAX 1012345
int n;
char s[17];
int m[MAX], mm=0;
int i=-1, b=0;

int main(){
  scanf("%d", &n);
  memset(s, '0', 16);
  s[n]='\0';

  printf("%s\n", s);

  while(!(b==n && i < 0)){
    if(i<0){
      s[n-1-b]=(s[n-1-b] == '0') ? '1': '0';
      printf("%s\n", s);
      m[mm++]=n-1-b;
      b++;
      i=mm-2;
    }else{
      s[m[i]]=(s[m[i]] == '0') ? '1': '0';
      printf("%s\n", s);
      m[mm++]=m[i];
      i--;
    }
  }
}
