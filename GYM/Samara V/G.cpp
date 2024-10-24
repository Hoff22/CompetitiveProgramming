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
    		res = ((res % MOD) * (a % MOD)) % MOD;
    	}
    	a = ((a % MOD) * (a % MOD)) % MOD;
    	b >>= 1;
    }
    return res; 
}

vector<int> g[N+1];


int main(){
	
	int n , q;

	scanf("%d %d", &n, &q);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	while(q--){
		long long u, v, k;
		scanf("%lld %lld %lld", &u, &v, &k);

		bool adj = false;

		for(int i : g[u]){
			if(i == v) adj = true;
		}

		long long ans = 0;
		if(adj){
			ans = k * pow_(k-1, n-1) % MOD;
		}
		else{
			ans = k * pow_(k-1, n-2) % MOD;
			ans = ans * (k-2) % MOD;
		}

		printf("%lld\n", ans);
	}

    return 0;

}