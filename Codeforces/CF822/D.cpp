#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	vector<long long> v(n + 1);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}

	vector<pair<long long, long long>> a;
	vector<pair<long long, long long>> b;

	long long needR = 0;
	long long needL = 0;

	long long cur = 0;
	long long cost = 0;
	for(int i = k+1; i <= n; i++){
		cur += v[i];

		cost = max(cost, -cur);
		if(cur >= 0){
			a.push_back({cost, cur});
			cur = 0;
		}
	}
	needR = cost;
	cur = 0;
	cost = 0;
	for(int i = k-1; i >= 1; i--){
		cur += v[i];

		cost = max(cost, -cur);
		if(cur >= 0){
			b.push_back({cost, cur});
			cur = 0;
		}
	}
	needL = cost;

	// for(auto c : a){
	// 	printf("(%lld %lld)\n", c.fi, c.se);
	// }
	// for(auto c : b){
	// 	printf("(%lld %lld)\n", c.fi, c.se);
	// }

	int i, j;
	i = j = 0;
	cur = v[k];
	while(i < a.size() or j < b.size()){
		bool good = 0;

		//printf("%d %d %lld\n", i, j, cur);

		if(i < a.size() and cur >= a[i].fi){
			cur = (cur + a[i].se);
			i++;
			good = 1;
		}
		if(j < b.size() and cur >= b[j].fi){
			cur = (cur + b[j].se);
			j++;
			good = 1;
		}

		if(!good) break;
	}

	//printf("%d %d %lld - f\n", i, j, cur);

	if(i == a.size() and cur >= needR){
		printf("YES\n");
		return;
	}
	if(j == b.size() and cur >= needL){
		printf("YES\n");
		return;
	}

	printf("NO\n");

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