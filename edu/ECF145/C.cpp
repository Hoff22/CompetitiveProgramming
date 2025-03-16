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

	vector<int> ans(n, 0);

	int cur = 0;
	for(int i = 0; i < n; i++){
		if(k - cur == 0){
			k = 0;
			ans[i] = -(cur*2)+1;
		}
		else if(k - (1+cur) >= 0){
			k -= (1+cur);
			cur++;
			ans[i] = 2;
		}
		else{
			ans[i] = -1000;
			cur = 0;
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
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