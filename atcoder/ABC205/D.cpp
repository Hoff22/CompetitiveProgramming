#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long v[N+1];
long long sum[N+2];
int n, q;

long long solve(long long k, int l, int r){

	// if(l+1 == r and sum[r] - sum[l-1] == k){
	// 	return v[l] + k;
	// }

	// int m = l + (r - l) / 2;

	// if(sum[m] - sum[l-1] >= k){
	// 	return solve(k, l, m);
	//	}
	// else{
	// 	return solve(k - sum[m] - sum[l-1], m, r);
	// }

	int m;

	while(l < r-1){
		m = l + (r - l) / 2;
		//printf("%lld\n", k);
		if(sum[m] - sum[l] >= k){
			r = m;
		}
		else{
			k -= (sum[m] - sum[l]); 
			l = m;
		}
	}

	return v[l] + k;

}

int main(){
	
	scanf("%d %d", &n, &q);

	for(int i = 1; i <= n; i++){
		long long x;
		scanf("%lld", &x);
		v[i] = x;
	}

	sort(v+1, v+n);

	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + (v[i] - v[i-1] - 1);
	}
	sum[n+1] = (10e18) - v[n];
	
	for(int i = 0; i < q; i++){
		long long k;
		scanf("%lld", &k);

		printf("%lld\n", solve(k, 0, n+1));
	}

    return 0;

}