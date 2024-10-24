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
	int n; cin >> n;

	if(n == 1){
		int x;
		cin >> x;
		cout << 0 << endl;
		return;
	}

	vector<int> a;
	vector<int> b;
	for(int i = 0; i < n/2; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	if(n%2){
		int t; cin >> t;
	}
	for(int i = 0; i < n/2; i++){
		int x; cin >> x;
		b.push_back(x);
	}

	reverse(b.begin(), b.end());

	int ans = abs(a[0] - b[0]);
	for(int i = 0; i < n/2; i++){
		ans = gcd(ans, abs(b[i] - a[i]));
	}

	int good = 1;
	for(int i = 0; i < n/2; i++){
		if(a[i] != b[i]) good = 0;
	}

	if(good){
		cout << 0 << endl;
		return;
	}

	cout << ans << endl;

}

/*

x x x x
y y y y




*/

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