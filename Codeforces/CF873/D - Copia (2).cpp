#include <bits/stdc++.h>

#define N 5000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

vector<int> a;
int DP[N+1][N+1];

void solve(){
	int n;
	cin >> n;
	a.assign(n+1,0);
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 0; i <= n; i++){
		for(int j = i; j <= n; j++){
			DP[i][j] = INF;
		}
	}


	for(int l = 1; l <= n ; l++){
		DP[l][l] = 0;
		int mx = a[l];
		for(int r = l+1; r <= n; r++){
			DP[l][r] = r-l;
			if(a[r] >= mx){
				DP[l][r] = min(DP[l][r], DP[l][r-1]);
				mx = a[r];				
			}
		}
	}

	for(int r = n; r <= 1; r--){
		DP[r][r] = 0;
		int mn = a[r];
		for(int l = r-1; l >= 1; l--){
			DP[l][r] = min(DP[l][r], r-l);
			if(a[l] <= mn){
				DP[l][r] = min(DP[l][r], DP[l+1][r]);
				mn = a[l];
			}
		}
	}

	long long ans = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ans += DP[i][j];
		}
	}

	cout << ans << endl;
}

/*

1 2 3 4 5 6
6-1 = 5

3-1 = 2
6-4 = 2



*/

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