#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int c[N];
	int a[N];
	int b[N];
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	for(int i = 0; i < n; i++){
		if(a[i] > b[i]){
			int temp = b[i];
			b[i] = a[i];
			a[i] = temp;
		}
	}

	long long dp[N];

	dp[0] = 0;

	for(int i = 1; i < n; i++){
		if(a[i] == b[i]) dp[i] = (b[i] - a[i]) + c[i] + 1;
		else dp[i] = max(dp[i-1] - (b[i] - a[i]) + 1 + c[i], (b[i] - a[i]) + c[i] + 1ll);
		// dp[i-1] - (b[i] - a[i]) + 1 + c[i];
		// (b[i] - a[i]) + c[i] + 1; 
	}

	printf("%lld\n", *max_element(dp, (dp + n)));

}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}