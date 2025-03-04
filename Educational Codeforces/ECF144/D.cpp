#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

typedef long long ll;

using namespace std;

/*

	AMIGO QUE TALVEZ ESTEJA LENDO ESTE CODIGO,

	EU TENHO 15 WA'S PQ EU TINHA ENTENDIDO QUE K PODIA SER
	ATEH 10^5. 

	ABAIXO A SOLUCAO OBVIA DO PROBLEMA.

	OBRIGADO PELA ATENCAO.

*/

ll n,x;
vector<ll> a;

ll dp[N+1][21][3];

ll go(int i, int k, int state){

	if(i > n){
		if(k == 0 and state > 0) return 0;
		else return -INF;
	}
	if(k < 0) return -INF;

	if(dp[i][k][state] != -1) return dp[i][k][state];
 
	if(state == 0){ // haven't opened window yet
		return dp[i][k][state] = max({
			go(i+1, k, 0),
			go(i+1, k-1, 0),
			go(i+1, k, 1) + a[i] - x,
			go(i+1, k-1, 1) + a[i] + x
		});
	}
	else if(state == 1){ // window is open
		return dp[i][k][state] = max({
			go(i+1, k, 2),
			go(i+1, k-1, 2),
			go(i+1, k, 1) + a[i] - x,
			go(i+1, k-1, 1) + a[i] + x
		});
	}
	
	// state == 2 // window is closed
	return dp[i][k][state] = max({
		go(i+1, k, 2),
		go(i+1, k-1, 2)
	});
}


void solve(){
	ll k;
	cin >> n >> k >> x;
	a.assign(n+1, 0);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		}
		cin >> a[i];
	}

	cout << max(go(1, k, 0), 0ll) << endl;
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