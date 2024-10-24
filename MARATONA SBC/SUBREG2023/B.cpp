#include <bits/stdc++.h>

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
	
	int n; cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> f(n);
	for(int i = 0; i < n; i++) f[i] = i+1;

	int ans = 0;
	while(a != f){
		vector<vector<int>> g(n+1, vector<int>());

		for(int i = 0)

		ans++;
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}