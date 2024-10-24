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

set<long long> rem;
vector<long long> c;
vector<pair<long long,long long>> ranges;
long long dp[N+1];

bool mysort(long long a, long long b){
	return ranges[a] < ranges[b];
}

bool mysearch(long long a, long long b){
	return ranges[a].fi < b;
}

long long solve(long long i, vector<long long>& idx){
	
	if(i >= idx.size()) return 0ll;

	// printf("(%lld : %lld)\n", ranges[idx[i]].fi, ranges[idx[i]].se);

	if(dp[i] != -1) return dp[i];

	long long nxtI = (long long)(lower_bound(idx.begin()+i, idx.end(), ranges[idx[i]].se + 1, mysearch) - idx.begin());

	// printf("nxt_I: %lld\n", nxtI);

	return dp[i] = max( solve(i+1, idx), solve(nxtI, idx) + c[idx[i]] );
}

void addRem(long long i, vector<long long>& idx){
	if(i >= idx.size()) return;

	long long nxtI = (long long)(lower_bound(idx.begin()+i, idx.end(), ranges[idx[i]].se + 1, mysearch) - idx.begin());

	if(solve(i+1, idx) > solve(nxtI, idx) + c[idx[i]]){
		addRem(i+1, idx);
	}
	else{
		rem.insert(idx[i]);
		addRem(nxtI, idx);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	long long n, k;
	scanf("%lld %lld", &n, &k);

	for(long long i = 0; i < n; i++){
		long long l, r;
		long long c_;
		scanf("%lld %lld %lld", &l, &r, &c_);
		ranges.push_back({l,r});
		c.push_back(c_);
	}

	long long ans = 0;

	for(long long i = 0; i < k; i++){
		vector<long long> idx;

		for(long long j = 0; j < n; j++){
			if(!rem.count(j)){
				idx.push_back(j);
			}
		}		

		sort(idx.begin(), idx.end(), mysort);

		memset(dp, -1 ,sizeof(dp));

		// for(long long j = 0; j < idx.size(); j++){
		// 	printf("(%lld : %lld) ", ranges[idx[j]].fi, ranges[idx[j]].se);
		// }
		// printf("\n");

		//printf("FEZKKK\n");
		ans += solve(0, idx);
		// fflush(stdin);
		addRem(0, idx);
	}

    printf("%lld\n", ans);

    return 0;

}