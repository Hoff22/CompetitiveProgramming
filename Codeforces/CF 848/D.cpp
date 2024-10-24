#include <bits/stdc++.h>

#define N 1000000
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;


void solve(){
	cin >> n;
	string a, b;
	cin >> a >> b;

	cout << a <<endl<< b << endl;

	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i]!=b[i]){


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