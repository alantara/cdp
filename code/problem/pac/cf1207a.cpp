#include <bits/stdc++.h>
using namespace std;

int t;
int b, p, f, h, c;

int main(void){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
		int ans = 0;
		if(c > h){
			swap(c, h);
			swap(p, f);
		}
		b = b/2;
		ans += min(b, p) * h;
		b -= p;
		if(b > 0){
			ans += min(b, f) * c;
		}
		printf("%d\n", ans);
	}
	return 0;
}
