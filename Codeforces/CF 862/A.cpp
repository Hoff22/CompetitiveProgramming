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

	if(n == 1){
		int b;
		cin >> b;
		cout << b << endl;
		return;
	}
	
	vector<int> a(n);

	int x = 0;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		x ^= a[i];
	}

	int t = x;
	while(t){
		if(t&1 and n%2==0){
			cout << -1 << endl;
			return;
		}
		t>>=1;
	}

	cout << x << endl;
}

/*

001
010
010
011

001
010
101

000
001
010
011

001
010
101

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