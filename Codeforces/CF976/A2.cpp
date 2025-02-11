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

typedef long long ll;

ll inv(ll a, ll b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

int n;
ll a[N+1], p[N+1], pc[N+1];
ll DP[N+1][12][2];


/*


A * p1p2 + Bp4p5 + A * p2p5 + B * p1p4 ->

0101
1011 -> 1110^2     -> 11000100


0101^2 -> 00011001
1011^2 -> 01111001 -> 01100000

*/

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		pc[i] = (((10000-p[i])%MOD) * inv(10000,MOD)) % MOD;   // probabilidade de nao pegar
		p[i] = (p[i] * inv(10000, MOD)) % MOD;					// probabilidade de pegar
	}

	for(int j = 0; j <= 11; j++){
		DP[0][j][0] = 1;
		DP[0][j][1] = 0;
	}

	for(int j = 0; j <= 11; j++){
		for(int i = 1; i <= n; i++){
			if((a[i] >> j) & 1){
				DP[i][j][0] = ((DP[i-1][j][1] * p[i]) % MOD + (DP[i-1][j][0] * pc[i]) % MOD) % MOD;  
				DP[i][j][1] = ((DP[i-1][j][0] * p[i]) % MOD + (DP[i-1][j][1] * pc[i]) % MOD) % MOD;  
			}
			else{
				DP[i][j][0] = DP[i-1][j][0];
				DP[i][j][1] = DP[i-1][j][1];
			}
		}
	}

	ll ans = 0;
	for(ll m = 0; m <= 1024; m++){
		ll pcur = 1;
		for(int j = 0; j <= 11; j++){
			pcur = (pcur * ( ((m>>j)&1) ? DP[n][j][1] : DP[n][j][0] )) % MOD;
		}

		ll sq = (m*m) % MOD;
		ans = (ans + (sq * pcur) % MOD) % MOD;
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}