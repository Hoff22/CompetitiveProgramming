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

// O(log_2(N))
long long pow_(long long a, long long b){
    long long res = 1;
    while(b){
    	if(b&1){
    		res = (res % MOD * a % MOD) % MOD;
    	}
    	a = (a % MOD * a % MOD) % MOD;
    	b >>= 1;
    }
    return res; 
}

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	long long ans = 0;
	int i = 0;
	while(k){

		if(k & 1){
			ans = (ans % MOD + pow_(n, i) % MOD) % MOD;
		}

		k >>= 1;
		i++;
	}

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}