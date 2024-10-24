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
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);
	vector<int> b(m);

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int ans = 0;	
	for(int i = 0, j = 0; i < n; i++){
		while(j < m and a[i]-k > b[j]) j++;
		if(j == m) break;
		if(a[i]+k >= b[j]) ans++, j++;
	}

	cout << ans << endl;
}

/*

45 60 60 80
30 60 75

*/

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}