#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, p;
	cin >> n >> p;

	vector<ll> a(n,0);
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n; i++) a.push_back(a[i]);

	vector<ll> sum(3*n, 0);
	for(int i = 0; i < 2*n; i++){
		if(i > 0) sum[i] = sum[i-1] + a[i];
		else sum[i] = a[i];
	}
	
	vector<vector<int>> j(31, vector<int>(2*n+1,2*n));
	for(ll i = 0, s = 0; i < n; i++){
		s += a[i];
		if(s >= p){
			j[0][0] = i+1;
			break;
		}
	}
	for(int i = 1; i < 2*n; i++){
		int l = 0;
		int r = n;
		while(l <= r){
			int m = (l+r)/2;
			if(sum[i+m]-sum[i-1] >= p){
				j[0][i] = i+m+1;
				r = m-1;
			}
			else{
				l = m+1;
			}
		}
	}

	for(int k = 1; k < 30; k++){
		for(int i = 0; i < 2*n; i++){
			j[k][i] = j[k-1][j[k-1][i]];
		}
	}

	// for(int k = 0; k <= 29; k++) cout << j[k][0] << " ";
	// cout << endl;
	// for(int k = 0; k <= 29; k++) cout << j[k][3] << " ";
	// cout << endl;

	for(int i = 0; i < n; i++){
		ll res = 0;
		int cur = i;
		for(int k = 29; k >= 0; k--){
			if(j[k][cur] <= i+n){
				cur = j[k][cur];
				res += (1ll<<k);
			}
			if(cur == i+n){
				res--;
				break;
			}
		}
		cout << res << " ";
	}
	cout << endl;
}