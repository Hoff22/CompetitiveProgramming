#include <bits/stdc++.h>

#define N 200100
#define MAX 1000000000
#define E 0.00000001
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n;

void solve(){
	int dp[N+1];
	map<int, int> cnt;

	memset(dp, 0, sizeof(dp));

	scanf("%d", &n);

	int mx = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		//a.push_back(x);
		mx = max(x, mx);
		cnt[x]++;
	}

	for(int i = 1; i < N; i++){
		dp[i] += cnt[i];

		for(int j = 1; j * i <= mx; j++){
			dp[j*i] = max(dp[j*i], dp[i]);
		}
	}

	int y = 0;
	for(int i = 1; i < N; i++){
		y = max(y, dp[i]);
	}

	printf("%d\n", n - y);
}

int main(){

	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	

    return 0;

}