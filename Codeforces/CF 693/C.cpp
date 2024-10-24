#include<bits/stdc++.h>

#define N 200000
#define INF 0x3f3f3f3f

using namespace std;

int a[N+1];
int dp[N+1];
int n;

int main(){
		
	int t;
	scanf("%d",&t);

	while(t--){
		scanf("%d", &n);
		
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		
		for(int i = n; i > 0; i--){
			if(i + a[i] > n){
				dp[i] = a[i];
			}
			else{
				dp[i] = a[i] + dp[i+a[i]];
			}

		}

		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans, dp[i]);
		}

		printf("%d\n", ans);
	}

	return 0;
}