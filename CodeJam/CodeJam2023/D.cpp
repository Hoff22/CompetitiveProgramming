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
	ll a;
	cin >> a;

	ll d = (a-1)/26;

	ll n = (1 + floor(sqrt(1+8*d))) / 2;

	ll back = (n-1)*n/2 * 26;

	ll ans = (ll)ceil(1.0*(a - back) / n);

	cout << (char)(ans + 'A' - 1) << endl;
	//cout << n << " " << back << " " << ans << endl;

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;

}