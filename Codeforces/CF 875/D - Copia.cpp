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

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

//	vector<multiset<int>> l(2*n+1, multiset<int>());
	vector<set<int>> wants(n, set<int>);

	ll ans = 0;

	for(int j = 0; j < n; j++){
		for(int x = a[j]; x <= 2*n; x += a[j]){
			wants[j].insert(x/a[j]);
		}
	}

	for(int i = 0; i < n; i++){
		
	}

	// for(int j = 0; j < n; j++){

	// 	for(int x = a[j]; x <= 2*n; x += a[j]){
	// 		ans += l[x/a[j]].count(x-b[j]);
	// 	}

	// 	l[a[j]].insert(b[j]);
	// }

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