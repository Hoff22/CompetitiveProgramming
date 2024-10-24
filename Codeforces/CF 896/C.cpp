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
	if(m == 1){
		cout << 0 << endl;
		for(int i = 0; i < n; i++){
			cout << 0 << endl;
		}
		return;
	}

	if(n == 1){
		cout << 2 << endl;
		for(int i = 0; i < m; i++){
			cout << i << " ";
		}
		cout << endl;
		return;
	}

	int k = min(m,n+1);
	cout << k << endl;

	set<int> can;
	for(int i = 0; i < m; i++) can.insert(i);

	for(int i = 0; i < k-1; i++){
		set<int> s = can;
		
		for(int j = i; j < k; j++){
			cout << j << " ";
			s.erase(j);
		}

		for(int j : s) cout << j << " ";

		cout << endl;
	}

	for(int i = k-1; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << j << " ";
		}
		cout << endl;
	}
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