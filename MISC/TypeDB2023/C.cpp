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
vector<pair<long long,long long>> b;

long long dp[N+1][2];

long long go(int i , int dir){
	// 0 = left
	// 1 = right

	if(i > n){
		return 0;
	}

	if(dp[i][dir] != -1) return dp[i][dir];

	if(dir){
		return dp[i][dir] = min(
			go(i+1, 1) + b[i].fi * b[i-1].se,
			go(i+1, 0) + b[i].se * b[i-1].se
		);
	}
	else{
		return dp[i][dir] = min(
			go(i+1, 1) + b[i].fi * b[i-1].fi,
			go(i+1, 0) + b[i].se * b[i-1].fi
		);
	}
}

void solve(){
	long long s;
	scanf("%d %lld", &n, &s);

	b.assign(n+1, {0ll,0ll});
	vector<long long> a(n+1);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		dp[i][0] = dp[i][1] = -1;
	}

	b[1] = {a[1],a[1]};
	b[n] = {a[n],a[n]};
	for(int i = 2; i < n; i++){
		if(a[i] > s){
			b[i] = {min(a[i] - s, s), max(a[i] - s, s)};
		}
		else{
			b[i] = {0ll,a[i]};
		}
	}

	printf("%lld\n", go(2, 1));
}

/*

xi ou yi serem 0 entao ai menor que s

xi | yi == 0 --> ai <= s

if ai == 0 --> xi == 0 and yi == 0

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