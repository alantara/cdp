#include <bits/stdc++.h>

int main(){

    long n;
    scanf("%ld", &n);

    printf("%ld ", n);
    while(n != 1){
        n = (n % 2 == 0) ? n/2: 3*n+1;
        printf("%ld ", n);
    }
}