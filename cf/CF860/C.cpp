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


	vector<long long> a(n);
	vector<long long> b(n);

	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	int ans = 1;
	long long x_b = b[0];
	for(int i = 0; i < n; i++){
		x_b = lcm(x_b, b[i]);
		if(a[i] % (x_b / b[i])){
			ans++;
			x_b = b[i];
		}
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