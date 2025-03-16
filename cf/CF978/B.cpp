#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;

	long long mx = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		sum += x;
		mx = max(mx, x);
	}

	cout << max((sum+k-1)/k, mx) << endl;
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