#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<ll> b = {a[0]};

	ll ans = 0;
	for(int i = 1; i < n; i++){
		if(a[i] >= 0 or b.back() >= 0){
			ans += max(b.back(), a[i]);
			b.push_back(a[i]);
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