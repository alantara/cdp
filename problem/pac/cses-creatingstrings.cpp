#include <bits/stdc++.h>

char str[9];
int strl;

int p = 1;

int freq[26];
int stfreq[26];

int st[8], stl = 0;

void renum(int n){
  if(n==0){
    for(int i = 0; i<stl; i++){
      printf("%c", 'a'+st[i]);
    }
    printf("\n");
  }

  for(int i = 0; i<26; i++){
    if(stfreq[i] != freq[i]){
      stfreq[i]++;
      st[stl++]=i;
      renum(n-1);
    }
  }
  stfreq[st[stl-1]]--;
  stl--;
}

int main(){
  scanf("%s", str);
  memset(freq, 0, 26);
  memset(stfreq, 0, 26);

  for(strl = 0; str[strl] != '\0'; strl++){
    freq[str[strl]-'a']++;
    p*=strl+1;
  }
  
  for(int i = 0; i<26; i++){
    for(int j=0; j<freq[i]; j++){
      p/=freq[i]-j;
    }
  }

  printf("%d\n", p);
  renum(strl);
}
