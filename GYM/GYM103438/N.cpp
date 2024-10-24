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

    vector<ll> a(n+1);
    vector<ll> b(n+1);

    for(int i = 0; i <= n; i++){
    	cin >> a[i];
    }

    for(int i = 0; i <= n; i++){
    	cin >> b[i];
    }

    ll ans = 0;

    for(int i = n; i > 0; i--){
    	ll of = b[i] - a[i];
    	if(of <= 0) continue;
    	
    	a[i-1] -= (of+1ll)/2ll;
    	ans += (of+1ll)/2ll;
    	a[i] += ((of+1ll)/2ll) * 2ll;
    }

    for(int i = 0; i <= n; i++){
    	if(b[i] > a[i]){
    		cout << -1 << endl;
    		return 0;
    	}
    }

    cout << ans << endl;

    return 0;

}