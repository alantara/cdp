#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int aux = 0, n = 0,p = 0;
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == '+'){
      aux ++;
    }
    else if(s[i] == '-'){
      aux --;
    }
    if(aux > n){
      n = aux;
      p = i + 1;
    }
    
  }
  cout << p << endl;
  return 0;
}