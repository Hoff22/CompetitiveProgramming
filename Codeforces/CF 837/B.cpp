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
	int n, m;
	scanf("%d %d", &n, &m);

	vector<set<long long>> f(n+1);

	for(int i = 0; i < m; i++){
		long long u, v;
		scanf("%lld %lld", &u, &v);

		f[u].insert(v);
		f[v].insert(u);
	}

	vector<long long> p(n+1);

	for(int i = 1; i <= n; i++){
		if(lower_bound(f[i].begin(), f[i].end(), i) == f[i].begin()){
			p[i] = 0;
		}
		else{
			p[i] = *(--lower_bound(f[i].begin(), f[i].end(), i));
		}
	}

	long long cnt = 0;
	long long cur = 0;
	for(long long i = 1; i <= n; i++){

		cur = max(cur, p[i]);
		cnt += (i - cur);
	}
	printf("%lld\n", cnt);

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