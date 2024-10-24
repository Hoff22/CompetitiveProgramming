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
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int sum = 0;
	int mn_odd = INF;
	int mn_even = INF;
	for(int i = 1; i <= n; i++){
		sum += (a[i]%2);
		if(a[i]%2){
			mn_odd = min(mn_odd, a[i]);
		}
		else{
			mn_even = min(mn_even, a[i]);
		}
	}

	if(sum == n or sum == 0){
		cout << "YES" << endl;
		return;
	}

	if(mn_even <= mn_odd){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
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