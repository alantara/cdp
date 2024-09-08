#include <bits/stdc++.h>
using namespace std;

int c, b, p;
int x, y, z;

int main(){
  scanf("%d %d %d", &c, &b, &p);
  scanf("%d %d %d", &x, &y, &z);
  int sum = 0;
  sum += max(0, x-c);
  sum += max(0, y-b);
  sum += max(0, z-p);
  printf("%d\n", sum);
  return 0;
}