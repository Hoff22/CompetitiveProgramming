#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;

	// a - x >= b - 2x
	// x >= b-a

	/*

	7 9
	6 7
	5 5

	*/

	if(k-n >= n){
		cout << 0 << endl;
	}
	else{
		cout << n - max(0, k-n) << endl;
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