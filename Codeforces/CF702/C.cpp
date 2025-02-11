#include <bits/stdc++.h>

#define N 10000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	long long x;
	scanf("%lld", &x);

	for(long long a = 1; a*a*a*1ll < x; a++){
		int l = 1;
		int r = N;
		long long b = 0;

		while(l <= r){
			b = (l + r) / 2;

			if(a*a*a*1ll + b*b*b*1ll == x){
				printf("YES\n");
				return;
			}
			if(a*a*a*1ll + b*b*b*1ll > x){
				r = b - 1;
			}
			else{
				l = b + 1;
			}
		}
	}

	printf("NO\n");
	return;
}
// 10000 10000 10000 = 1000000000
int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}