#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLONG 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int n;
vector<int> l;
vector<int> r;

void solve(){
	int k;
	cin >> n >> k;

	l.assign(n,0);
	r.assign(n,0);

	vector<long long> acc(n, 0);

	for(int i = 0; i < n; i++){
		cin >> l[i];
	}
	for(int i = 0; i < n; i++){
		cin >> r[i];
	}

	acc[0] = r[0] - l[0] + 1;
	for(int i = 1; i < n; i++){
		acc[i] = acc[i-1] + (r[i] - l[i] + 1);
	}

	if(acc[n-1] < k){
		cout << -1 << endl;
		return;
	}

	// for(int i = 0; i < n; i++) cout << acc[i] << " ";
	// cout << endl;
	long long ans = INFLONG;
	long long cnt = 0;
	for(int i = 0; i < n; i++){
		if(acc[i] == k){
			ans = min(ans, 2ll*(i+1) + r[i]);
		}
		else if(acc[i] > k){
			int off = min(cnt,acc[i] - k);
			//cout << i << ": " << off << endl;
			ans = min(ans, 2ll*(i+1) - (2*off) + r[i] - ((acc[i] - k) - off) );
		}

		if(r[i]-l[i] == 0) cnt++;
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