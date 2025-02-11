#include <bits/stdc++.h>

#define N 10000000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long sum[N+1];
long long dp[N+1];

void solve(){

	int c;
	scanf("%d", &c);

	printf("%lld\n", dp[c]);
}

int main(){
	
	int t;
	scanf("%d", &t);

	memset(dp, -1, sizeof(dp));

	for(int i = 1; i < N; i++){
		int j = i;
		while(j < N){

			sum[j] += i;

			j+=i;
		}
		if(sum[i] <= N and dp[sum[i]] == -1){
			dp[sum[i]] = i;
		} 
	}

	while(t--){
		solve();
	}

    return 0;
}