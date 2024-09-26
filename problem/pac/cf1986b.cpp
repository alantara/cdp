#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, mat[212][212];

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        scanf("%d", &mat[i][j]);
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        int bn = 0;
        if(i-1 >= 0) bn = max(bn, mat[i-1][j]);
        if(i+1 < n)  bn = max(bn, mat[i+1][j]);
        if(j-1 >= 0) bn = max(bn, mat[i][j-1]);
        if(j+1 < m)  bn = max(bn, mat[i][j+1]);
        if(mat[i][j] > bn) mat[i][j] = bn;
        printf("%d ", mat[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}