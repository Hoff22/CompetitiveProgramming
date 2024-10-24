#include <bits/stdc++.h>

#define N 200000
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
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	long long ans1, ans2;
	ans1 = ans2 = 0;

	for(int i = 0; i < n; i++){
		ans1 += abs(a[i]-a[n/2]);
	}
	for(int i = 0; i < n; i++){
		ans2 += abs(a[i]-a[(n+1)/2]);
	}

	cout << min(ans1, ans2) << endl;
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