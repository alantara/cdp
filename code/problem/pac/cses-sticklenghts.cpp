#include <bits/stdc++.h>
#define MAX 212345
using namespace std;
typedef long long ll;

int n, p[MAX];

ll find(int j){
	ll sum = 0; 
	for(int i = 0; i < n; i++){
		sum += abs(p[i]-p[j]);
	}
	return sum;
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	sort(p, p+n);
	ll m = find(n/2), d;
	if(!(n & 1) && (d = find(n/2 + 1)) < m){
		m = d;
	}
	printf("%lld\n", m);	
	return 0;
} 
