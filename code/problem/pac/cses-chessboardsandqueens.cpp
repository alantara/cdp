#include <bits/stdc++.h>

int cb[64];
int st[1012345], stp=0;
long long sum=0;

void rqueen(int r){
  if(r==8){
    sum++;
    return;
  }

  for(int i = 0; i < 8; i++){
    if(cb[8*r+i]==1){
      int n = 0;

      for(int j=1; (r+j) < 8; j++){
        int down = 8*(r+j) + i;
        int left = 8*(r+j) + i - j;
        int right = 8*(r+j) + i + j;

        if(cb[down] != 0){
          cb[down]=0;
          st[stp++]=down;
          n++;
        }

        if(left % 8 < down % 8 && cb[left] != 0){
          cb[left]=0;
          st[stp++]=left;
          n++;
        }
        
        if(right % 8 > down % 8 && cb[right] != 0){
          cb[right]=0;
          st[stp++]=right;
          n++;
        }

      }
      rqueen(r+1);

      for(int i=0; i<n; i++){
        cb[st[--stp]]=1;
      }
    }
  }
}

int main(){
  char s[9];
  for(int i = 0; i < 8; i++){
    scanf("%s", s);

    for(int j = 0; j<8; j++){
      cb[8*i+j]=(s[j] == '.') ? 1 : 0;
    }
  }

  rqueen(0);  
  printf("%lld", sum);
}
