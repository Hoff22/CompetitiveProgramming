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
	scanf("%d %d", &n, &k);

	vector<pair<int,int>> a(n);
	for(int i = 0; i < n; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		
		a[i] = {l,r};
	}

	for(int i = 0; i < n; i++){
		if(a[i].se == a[i].fi and a[i].se == k){
			cout << "YES\n";
			return;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;

			if(a[i].se == a[j].fi and a[i].se == k){
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}