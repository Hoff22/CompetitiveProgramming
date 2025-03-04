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
	vector<int> a(2*n);
	
	for(int i = 0; i < 2*n; i++){
		cin >> a[i];
	}	

	sort(a.begin(), a.end());
	
	long long ans = 0;
	vector<pair<int,int>> p;
	for(int i = 0; i < n-1; i++){
		ans += abs(a[i+1] - a[i]);
		ans += abs(a[i+n+1] - a[i+n]);

		p.push_back({a[i], a[i+n]});
	}
	p.push_back({a[n-1], a[2*n-1]});

	cout << ans << endl;
	for(auto [x,y] : p) cout << x << " " << y << endl;
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