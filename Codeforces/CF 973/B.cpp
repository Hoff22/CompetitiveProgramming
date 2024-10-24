#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<long long> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n-2; i++){
		a[n-1] -= a[i];
	}

	cout << a.back() - a[n-1] << endl;
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