#include <bits/stdc++.h>

#define MAX 10000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#define N 2000


int a[2][N+1];
ll s;
ll pre[N+1][N+1];
vector<int> v;

ll DP[N+2][100];

ll dp(int l, int k){
	if(!k and l != v.size()){
		return 0x3f3f3f3f3f3f3f3f;
	}
	if(l == v.size()){
		if(k) return 0x3f3f3f3f3f3f3f3f;
		return 0;
	}

	if(DP[l][k] != -1) return DP[l][k];
	
	ll res = 0x3f3f3f3f3f3f3f3f;

	for(int j = l; j < v.size(); j++){
		res = min(
			res,
			dp(j+1, k-1) + pre[l][j]
		);
	}

	return DP[l][k] = res;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k >> s;
	s *= MAX;

	for(int i = 0; i < n; i++){
		long double x; cin >> x;
		a[0][i] = (x * MAX);
		v.push_back(a[0][i]);
	}
	for(int i = 0; i < m; i++){
		long double x; cin >> x;
		a[1][i] = (x * MAX);
		v.push_back(a[1][i]);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			ll pm = 0;
			for(int u = i; u <= j; u++){
				pm += v[u];
			}
			pm /= (j-i+1);
			for(int u = i; u <= j; u++){
				pre[i][j] += abs(pm-v[u]) * abs(pm-v[u]) + (s/2) * (s/2);
			}
		}
	}

	memset(DP, -1, sizeof(DP));

	cout << fixed << setprecision(18) << 1.0 * dp(0,k) / (MAX*MAX) << endl;

	return 0;

}