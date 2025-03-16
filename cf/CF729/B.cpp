#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	long long n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);


	if(a == 1){
		if((n-1) % b == 0) printf("Yes\n");
		else printf("No\n");
		return;
	}


	for(long long x = 1; x <= n; x *= a){
		for(long long y = 1; y <= n; y *= a){
			if((n-x) % b*y == 0){
				printf("Yes\n");
				return;
			}
		}
	}
	
	printf("No\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}