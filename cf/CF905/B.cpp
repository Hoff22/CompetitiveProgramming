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
	int n, k;
	cin >> n >> k;

	if(k != 4){
		int ans = INF;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			ans = min(ans, ((x+k-1)/k) * k - x);
		}

		cout << ans << endl;
	}
	else{
		if(n == 1){
			int x; cin >> x;
			cout << ((x+k-1)/k) * k - x << endl;
			return;
		}

		int cnt3 = 0;
		int cnt2 = 0;
		int cnt1 = 0;
		int cnt0 = 0;

		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x%4 == 3) cnt3++;
			if(x%4 == 1) cnt1++;
			if(x%4 == 2) cnt2++;
			if(x%4 == 0) cnt0++;
		}

		if(cnt0) cout << 0 << endl;
		else if(cnt2 > 1) cout << 0 << endl;
		else if(cnt3 or (cnt2 and cnt1)) cout << 1 << endl;
		else if(cnt1 > 1) cout << 2 << endl;
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