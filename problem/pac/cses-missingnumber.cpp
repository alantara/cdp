#include <bits/stdc++.h>

#define MAX 201234

int n, a;
int h[MAX];

int main(){
    scanf("%d", &n);
    memset(h, 0, sizeof(h));

    for(int i = 0; i < n-1; i++){
        scanf("%d", &a);
        h[a] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(h[i] == 0)
            printf("%d", i);
    }
}