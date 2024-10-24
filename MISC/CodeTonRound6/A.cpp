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
	int n, k, x;
	cin >> n >> k >> x;
	if(x < k-1 or n < k) cout << -1 << endl;
	else{
		int ans = 0;
		for(int i = 0; i < k; i++){
			ans += i;
		}
		for(int i = 0; i < n-k; i++){
			if(k == x){
				ans += (x-1);
			}
			else{
				ans += x;
			}
		}
		cout << ans << endl;
	}
}

/*
0 1 2 3 3

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