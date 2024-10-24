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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);

	int x = 0;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		x ^= a[i];
	}

	int mx = x;
	int mn = x;

	if(n%2){
		for(int i = 0; i < m; i++){
			cin >> b[i];
			mx |= b[i];
		}

		cout << mn << " " << mx << endl;
	}
	else{
		for(int i = 0; i < m; i++){
			cin >> b[i];
			mn &= (~b[i]);
		}

		cout << mn << " " << mx << endl;	
	}
}

/*


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