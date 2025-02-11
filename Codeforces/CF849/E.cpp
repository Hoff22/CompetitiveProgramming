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

int n;
vector<long long> a;
long long dp[N+1][2];
bool seen[N+1][2];

long long go(int i, int flipped){
	if(i > n) return 0;

	if(seen[i][flipped]) return dp[i][flipped];
	seen[i][flipped] = true;

	if(flipped){
		return dp[i][flipped] = max(
			go(i+1, 0) + a[i], // not flipped
			go(i+1, 1) - (- a[i-1]) + (- (- a[i-1]) - a[i]) // flipped
		);
	}
	else{
		return dp[i][flipped] = max(
			go(i+1, 0) + a[i], // not flipped
			go(i+1, 1) - a[i-1] + (- a[i-1] - a[i]) // flipped
		);
	}

}

void solve(){
	scanf("%d", &n);
	a.assign(n+1, 0);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		seen[i][1] = seen[i][0] = false;
	}

	printf("%lld\n", go(2, 0) + a[1]);
}

/*

100 2 -3 7 50

 4 -5 -8

-4  5 -8

-4 -5  8





*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}