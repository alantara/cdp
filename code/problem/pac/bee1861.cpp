#include <bits/stdc++.h>
using namespace std;

char p[15], q[15];
map<string , int> k;

int main(void){
  while(scanf(" %s %s", p, q) != EOF){
    if(k[p] >= 0)
      k[p]++;
    k[q] = -1;
  }
  printf("HALL OF MURDERERS\n");  
  for(auto& [key, value] : k){
    if(value >= 0) printf("%s %d\n", key.c_str()  , value);
  }
  
  return 0;
}