#include <bits/stdc++.h>
using namespace std;
#define MAX 112

int n;
int bufp;
char em[MAX], buf[MAX];

set<string> s;

int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%s", em);
    int at = 0, plus = 0;
    bufp = 0;
    for(int i = 0; em[i] != '\0'; i++){
      if(em[i] == '@'){
        at = 1;
        plus = 0;
      }
      if(em[i] == '+'){
        plus = 1;
        continue;
      }
      if(at == 0 && em[i] == '.') continue;
      if(!plus) buf[bufp++] = em[i];
    }
    buf[bufp] = '\0';
    if(s.find(string(buf)) == s.end()){
      s.insert(string(buf));
    }
  }
  printf("%d\n", (int)s.size());
  return 0;
}