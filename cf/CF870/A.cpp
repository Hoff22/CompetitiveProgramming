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
	vector<int> a(n);

	set<int> s;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<int> cnt(n+1, 0);

	// cout << i << endl;
	for(int j = 0; j < n; j++){
		// cout << a[j] << " ";
		cnt[a[j]]++;
	}

	for(int i = 0; i <= n; i++){
		int sum = 0;
		for(int j = i+1; j <= n; j++){
			sum += cnt[j];
		}

		if(sum == i){
			cout << i << endl;
			return;
		}
	}

	cout << -1 << endl;
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