#include <bits/stdc++.h>

#define N 250
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

typedef long long ll;

int n;
ll c[2*N+1][2*N+1];

void solve(){
	cin >> n;

	for(int i = 0; i < 2*n; i++){
		for(int j = 0; j < 2*n; j++){
			cin >> c[i][j];
		}
	}
	
	ll sum = 0;
	for(int i = n; i < 2*n; i++){
		for(int j = n; j < 2*n; j++){
			sum += c[i][j];
		}
	}

	cout << sum + min({c[0][n],	c[2*n-1][n-1], c[n][0],	c[n-1][2*n-1], c[0][2*n-1],	c[2*n-1][0], c[n-1][n],	c[n][n-1]}) << endl;
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