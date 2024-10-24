#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;

	int ans = 0;
	vector<int> a(n+1);
	vector<int> p(n+1,0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(p[a[i]-1] == 0) ans++;
		p[a[i]] = i;
	}
	
	while(m--){
		int l, r;
		cin >> l >> r;

		if(l > r) swap(l,r);

		if(a[l] == a[r]-1){
			ans++;
			if(l < p[a[l]-1] and p[a[l]-1] < r) ans--;
			if(l < p[a[r]+1] and p[a[r]+1] < r) ans--;
		}
		else if(a[r] == a[l]-1){
			ans--;
			if(l < p[a[l]+1] and p[a[l]+1] < r) ans++;
			if(l < p[a[r]-1] and p[a[r]-1] < r) ans++;
		}
		else{
			if(l < p[a[l]-1] and p[a[l]-1] < r) ans--;
			if(l < p[a[l]+1] and p[a[l]+1] < r) ans++;

			if(l < p[a[r]-1] and p[a[r]-1] < r) ans++;
			if(l < p[a[r]+1] and p[a[r]+1] < r) ans--;
		}

		p[a[l]] = r;
		p[a[r]] = l;

		swap(a[l], a[r]);

		cout << ans << endl;
	}
}

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