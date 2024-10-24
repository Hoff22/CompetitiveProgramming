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
	int n;
	cin >> n;
		
	long long ans = 0;
	vector<int> p;
	for(int k = 1; k <= n; k++) p.push_back(k);
	for(int i = 1; i <= n; i++){
		long long cur = 0;
		long long mx = 0;
		for(int j = 1; j < i; j++) cur += j*j;
		for(int l = i, r = n; l <= r; l++, r--){
			cur += l*r;
			if(l!=r) cur += l*r;
			mx = max(mx, 1ll*l*r);
		}

		ans = max(ans, cur - mx);
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