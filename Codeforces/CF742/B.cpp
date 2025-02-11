#include <bits/stdc++.h>

#define N 300000
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

int dp[N+1];

void solve(){
	int a, b;
	scanf("%d %d", &a, &b);

	if(dp[a-1] == b){
		printf("%d\n", a);
	}
	else{
		printf("%d\n", a + 1 + ((dp[a-1] ^ b) == a));
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	

	dp[0] = 0;
	for(int i = 1; i <= 300000; i++){
		dp[i] = dp[i-1] ^ i;
	}

	while(t--){
		solve();
	}
    return 0;

}