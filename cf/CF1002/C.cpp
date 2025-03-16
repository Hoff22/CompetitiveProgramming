#include <bits/stdc++.h>

#define N 300
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<bool> seeni;
vector<bool> seenj;
map<int,vector<pair<int,int>>> w;

int dfs(int i, int j, int k){
	seeni[i] = 1;
	seenj[j] = 1;
	int res = 1;
	// cout << i << ", " << j  << ": "  << k << endl;
	for(auto [i2, j2] : w[k+1]){
		if(seeni[i2] or seenj[j2]) continue;
		res = max(res, 1 + dfs(i2, j2, k+1));
	}
	seeni[i] = 0;
	seenj[j] = 0;
	return res;
}

void solve(){
	int n;
	cin >> n;

	vector<vector<ll>> a(n, vector<ll>(n));
	w.clear();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
		reverse(a[i].begin(), a[i].end());
		for(int j = 0; j < n; j++){
			if(j>0) a[i][j] = a[i][j-1] + a[i][j];
			if(a[i][j] <= n) w[a[i][j]].push_back({i,j+1});
		}
	}


	// for(int i = 1; i <= n; i++){
	// 	cout << i << ": ";
	// 	for(auto [ii, jj] : w[i]){
	// 		cout << "(" << ii << " " << jj << ") ";
	// 	}
	// 	cout << endl;
	// }
	seeni = vector<bool>(n,0);
	seenj = vector<bool>(n,0);
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dfs(i,0,0));
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