#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;
	int l = 0;
	int r = 1000000000;

	while(l <= r){
		int m = l + (r-l) / 2;
		int cur = 0;
		for(int i = 1; i < n; i++){
			if(a[i] - a[i-1] > m){
				cur += ((a[i] - a[i-1] + m - 1) / m) - 1;
			}
		}

		// cout << l << " " << r << " " << m << ": " << cur << endl;

		if(cur > k){
			l = m+1;
		}
		else{
			ans = m;
			r = m-1;
		}
	}

	cout << ans << endl;
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