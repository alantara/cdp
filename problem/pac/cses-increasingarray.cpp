#include <bits/stdc++.h>

int n, prev, now;
long sum = 0;

int main(){
    scanf("%d", &n);
    scanf("%d", &prev);
    for(int i = 1; i < n; i++){
        scanf("%d", &now);
        if(prev-now > 0)
        {
            sum += prev-now;
        }
        else{
            prev = now;
        }
    }
    printf("%ld", sum);
}