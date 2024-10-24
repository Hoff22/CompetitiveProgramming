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

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.se != b.se) return a.se < b.se;
	else return a.fi < b.fi;
}

void solve(){
	int n, m , q;
	scanf("%d%d%d", &n, &m, &q);

	vector<pair<int,int>> f;
	vector<int> a(m+2, 0);

	for(int i = 0; i < n; i++){
		int l,r;
		scanf("%d %d", &l, &r);
		f.push_back({l,r});
	}

	sort(f.begin(), f.end(), comp);

	int cur = 0;
	int j = f.size()-1;
	int l,r;
	if(j >= 0){
		l = f[j].fi;
		r = f[j].se;
	}
	else{
		l = -1;
		r = -1;
	}
	for(int i = m; i >= 1; i--){

		if(i > r){
			cur++;
			a[i] = max(a[i+1], cur);
		}
		if(i >= l and i <= r){
			a[i] = a[i+1];
		}
		if(i < l){
			j--;
			if(j >= 0){
				l = f[j].fi;
				r = f[j].se;
			}
			else{
				l = -1;
				r = -1;
			}
			cur = (i > r);
			a[i] = max(a[i+1], cur);
		}
	}

	reverse(a.begin(), a.begin() + m + 2);

	// for(int i = 1; i <= m; i++){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");

	while(q--){
		int x;
		scanf("%d", &x);

		int ans = lower_bound(a.begin(), a.begin() + m + 1, x) - a.begin();

		if(ans == m+1){
			printf("-1 -1\n");
			continue;
		}

		int xl = m - ans + 1;
		int xr = xl + x - 1; 

		printf("%d %d\n", xl , xr);
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}