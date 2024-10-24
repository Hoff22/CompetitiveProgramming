#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	long long x, n;
	scanf("%lld %lld", &x, &n);


	if(n % 4 == 0){
		printf("%lld\n", x);
	}
	else if(n % 4 == 3){
		if(x%2){
			printf("%lld\n", x - n - 1);
		}
		else{
			printf("%lld\n", x + n + 1);
		}
	}
	else if(n % 4 == 2){
		if(x%2){
			printf("%lld\n", x - 1);
		}
		else{
			printf("%lld\n", x + 1);
		}
	}
	else if(n % 4 == 1){
		if(x%2){
			printf("%lld\n", x + n);
		}
		else{
			printf("%lld\n", x - n);
		}
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}