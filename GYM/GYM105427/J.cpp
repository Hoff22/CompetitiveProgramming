#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;

	vector<long long> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	reverse(a.begin()+k, a.end());

	long long ans = 0;
	for(int i = 0; i < min(n,k); i++){
		long long x = a[i];
		if(i+(n-k) >= k) x += a[i+(n-k)];
		ans = max(x, ans);
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
    return 0;
}