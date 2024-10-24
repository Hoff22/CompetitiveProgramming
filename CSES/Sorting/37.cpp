#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define N 400024
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, t;
	cin >> n >> t;

	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	long long l = 0;
	long long r = 1000000000000000000;

	long long ans = 0;

	while(l <= r){
		long long m = l + (r-l)/2;

		long long amt = 0;
		for(int i = 0; i < n; i++){
			amt += m/a[i];
			if(amt >= t) break;
		}

		if(amt >= t){
			ans = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	cout << ans << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}