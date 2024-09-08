#include <bits/stdc++.h>

int n;
int a;
std::vector<int> v;

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int s = 0;
    for(int i = 1; i != v.size(); i++){
        if(v[i-1] != v[i]){
            s++;
        }
    }
    printf("%d", s+1);
}
