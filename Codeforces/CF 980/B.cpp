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

	map<ll,ll> cnt;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		cnt[x]++;

	}
	ll ans = 0;
	ll sum = 0;
	ll cur = 0;
	while(k > sum){
		ll x, c;
		tie(x,c) = *cnt.begin();
		cnt.erase(x);
		sum += n * (x-cur);
		n -= c;
		if(k > sum) ans += c;
		cur = x;
	}
	cout << k + ans << endl;
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