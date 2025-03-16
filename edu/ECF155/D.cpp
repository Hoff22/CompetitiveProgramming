#include <bits/stdc++.h>

#define N 300004
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n;
	cin >> n;
	
	vector<int> a(n+1);

	for(int i = 1; i <= n; i++) cin >> a[i];

	long long ans = 0;

	for(int i = 0; i <= 30; i++){
		long long qnt[2];
		long long sum[2];

		long long cur = 0;
		int acc = 0;
		qnt[0] = 1;
		qnt[1] = sum[0] = sum[1] = 0; 
		for(int j = 1; j <= n; j++){
			acc += ((a[j] >> i) & 1);
			qnt[acc%2]++;
			sum[acc%2] += j;
			if(acc) cur += ((1<<i) * (((j*qnt[!(acc%2)]) % MOD - sum[!(acc%2)]) % MOD)) % MOD;
		}
		ans += cur;
		ans %= MOD;
		// cout << i << ": " << ans << endl;
	}

	cout << (ans + MOD) % MOD << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}