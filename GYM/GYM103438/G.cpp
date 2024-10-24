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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		
	int n;

	cin >> n;

	vector<ll> v;

	ll ans = 0;
	for(int i = 0; i < 2*n; i++){
		ll a, b; cin >> a >> b;
		ans += max(a,b);
		v.push_back(a+b);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++){
		ans -= v[i];
	}

	cout << ans << endl;

    return 0;

}