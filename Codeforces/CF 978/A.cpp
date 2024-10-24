#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

void solve(){
	int n, r;
	cin >> n >> r;
	int ans = 0;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ans += a[i];
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int i = 0;
	for(i = 0; i < n; i++){
		if(r - (a[i]+1)/2 < 0){
			break;
		}
		r -= (a[i]+1)/2;
	}

	// cout << " " << r << endl;
	int cnt = 0;
	if(i < n){
		while(r and a[i]){
			r -= 1;
			a[i] -= min(a[i], 2);
		}

		for(; i < n; i++){
			cnt += a[i];
		}
	}

	// cout << cnt << endl;

	cout << ans-cnt*2 << endl;

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