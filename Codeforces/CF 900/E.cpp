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

void solve(){
	int n; cin >> n;
	vector<long long> a(n+1);
	vector<vector<long long>> acc(31, vector<long long>(n+1,0));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 0; j < 31; j++){
			acc[j][i] = acc[j][i-1] + ((a[i]>>j) & 1);
		}
	}

	int q;
	cin >> q;

	while(q--){
		int lf, k;
		cin >> lf >> k;
		int l = lf;
		int r = n;
		int ans = -1;
		while(l <= r){
			int m = (l+r)/2;

			long long val = 0;
			for(int j = 0; j < 31; j++){
				if(acc[j][m]-acc[j][lf-1] == m-lf+1) val += (1<<j);
			}

			if(val >= k){
				ans = m;
				l = m+1;
			}
			else{
				r = m-1;
			}
		}

		cout << ans << " ";
	}
	cout << endl;
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