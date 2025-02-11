#include <bits/stdc++.h>

#define N 100000
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

vector<vector<int>> f(N+1, vector<int>());

vector<int> factors(int n){
	vector<int> r;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			r.push_back(i);
			if(n/i != i) r.push_back(n/i);
		}
	}
	return r;
}

void solve(){

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> a(n+1);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	sort(a.begin()+1, a.end());

	vector<int> cnt(m+1, 0);
	set<int> seen;

	int ans = INF;

	int l = 1;
	for(int r = 1; r <= n; r++){

		for(int d : f[a[r]]){
			if(d <= m){
				seen.insert(d);
				cnt[d]++;
			}
		}

		while(seen.size() == m and l <= r){
			ans = min(a[r] - a[l], ans);

			for(int d : f[a[l]]){
				if(d <= m){
					cnt[d]--;
					if(cnt[d] == 0) seen.erase(d);
				}
			}
			//printf("%d %d %d\n", l, r, ans);
			l++;
		}
	}

	if(ans == INF){
		printf("-1\n");
	}
	else{
		printf("%d\n", ans);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);

	for(int i = 1; i <= N; i++){
		f[i] = factors(i);
	}
	
	while(t--){
		solve();
	}
    return 0;

}