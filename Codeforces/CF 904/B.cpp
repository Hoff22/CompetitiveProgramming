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
	long long n; cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++){
		char c; cin >> c;
		a[i] = (c == '1');
	}
	
	reverse(a.begin(), a.end());

	vector<long long> ans(n+1, -1);

	long long cnt = 0;
	long long mvs = 0;
	for(int i = 0; i < n; i++){
		mvs += cnt * !a[i];
		cnt += a[i];
		ans[i-cnt+1] = mvs;
	}

	// cout << "3" << endl;

	//reverse(ans.begin(), ans.end());

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
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