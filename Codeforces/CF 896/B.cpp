#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, k, a, b;
	cin >> n >> k >> a >> b;

	vector<long long> x(n+1);
	vector<long long> y(n+1);

	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}

	long long direct = abs(x[a]-x[b]) + abs(y[a]-y[b]);

	long long dak = 0x3f3f3f3f3f3f3f3fll;
	for(int i = 1; i <= k; i++){
		dak = min(dak, abs(x[a]-x[i]) + abs(y[a]-y[i]));
	}
	long long dbk = 0x3f3f3f3f3f3f3f3fll;
	for(int i = 1; i <= k; i++){
		dbk = min(dbk, abs(x[b]-x[i]) + abs(y[b]-y[i]));
	}

	cout << min(direct, dak+dbk) << endl;
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