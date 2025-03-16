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
	vector<pair<int,int>> a(n+1);
	vector<int> b(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi;
		a[i].se = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	sort(a.begin()+1, a.end());
	sort(b.begin()+1, b.end());

	vector<int> ans(n+1);

	for(int i = 1; i <= n; i++){
		ans[a[i].se] = b[i];
	}

	for(int i = 1; i <= n; i++){
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