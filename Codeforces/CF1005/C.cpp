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

void solve(){
	int n;
	cin >> n;

	vector<ll> a(n);

	for(int i = 0; i < n; i++) cin >> a[i];

	vector<ll> b = {a[0]};
	for(int i = 1; i < n; i++){
		if((a[i] > 0) == (b.back() > 0)){
			b.back() += a[i];
		}
		else{
			b.push_back(a[i]);
		}
	}

	n = b.size();

	vector<ll> accP(n), accN(n);
	accP[0] = (b[0] > 0) * abs(b[0]);
	for(int i = 1; i < n; i++){
		accP[i] = accP[i-1] + (b[i] > 0) * abs(b[i]);
	}
	accN.back() = (b.back() < 0) * abs(b.back());
	for(int i = n-2; i >= 0; i--){
		accN[i] = accN[i+1] + (b[i] < 0) * abs(b[i]);
	}

	// for(int i = 0; i < n; i++) cout << accP[i] << " ";
	// cout << endl;
	// for(int i = 0; i < n; i++) cout << accN[i] << " ";
	// cout << endl;

	ll ans = 0;
	for(int i = 0; i < n ; i++){
		ans = max(ans, accP[i] + accN[i]);
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