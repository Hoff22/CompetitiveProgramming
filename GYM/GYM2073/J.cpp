#include <bits/stdc++.h>

#define N 505
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
int pos[N+1];
ll DP[N+1][N+1];

ll dp(int l, int r){
	if(l==r) return 0;

	if(DP[l][r] != -1) return DP[l][r];

	ll res = 0x3f3f3f3f;

	for(int i = l; i < r; i++){
		res = min(
			res, 
			dp(l,i) + dp(i+1,r) + abs(pos[l]-pos[i+1])
		);
	}

	return DP[l][r] = res;
}

void solve(){
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;

	ll ans = 0;

	for(int i = 0; i < n; i++){
		pos[a[i]] = i;
	}

	memset(DP, -1, sizeof(DP));
	cout << dp(1,n) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}