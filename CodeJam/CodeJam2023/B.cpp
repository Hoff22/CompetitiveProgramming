#include <bits/stdc++.h>

#define N 100000
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
	long long m, r, n;
	cin >> m >> r >> n;

	vector<long long> x(n);

	for(int i = 0; i < n; i++){
		cin >> x[i];
	}

	// int last = 0;
	// for(int i = 0; i < n; i++){
	// 	if(x[i] - last > r*2){
	// 		cout << "IMPOSSIBLE" << endl;
	// 		return;
	// 	}
	// 	last = x[i];
	// }

	// if(m - x[n-1] > r*2){
	// 	cout << "IMPOSSIBLE" << endl;
	// 	return;
	// }

	long long i = r;
	int last = -1;

	for(int j = 0; j < n; j++){
		if(x[j] - r <= 0){
			i = x[j] + r;
			last = j;
		}
	}

	if(last == -1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	int ans = 1;
	while(i < m){
		auto p = upper_bound(x.begin(), x.end(), i+r);
		//cout << i << " " << last << " " << (int)(p-x.begin())<<":"<< *p << endl;
		if(p == x.begin()){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		p--;
		if(last == (int)(p-x.begin())){
			cout << "IMPOSSIBLE" << endl;
			return;
		}

		last = (int)(p-x.begin());
		i = *p + r;
		ans++;
	}

	cout << ans << endl;

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