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

set<int> forbidden;
vector<pair<long long,long long>> v(61);
map<pair<int, long long>, long long> dp;
long long a, b, d;
long long t;

void solve(){
	dp.clear();
	forbidden.clear();

	scanf("%lld %lld %lld", &a, &b, &d);

	long long ab = a | b;

	t = 0;

	int i = 0;
	while(ab){
		if(ab % 2 == 1) forbidden.insert(i);
		ab >>= 1;
		i++;
	}

	for(int j = 0; j <= 60; j++){
		v[j].fi = (1ll<<j) % d;
		v[j].se = (1ll<<j);
	}

	if(go(0, 0) > -1){
		printf("%lld\n", go(0,0) | (a | b));
	}
	else{
		printf("-1\n");
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int p;
	scanf("%d", &p);
	
	while(p--){
		solve();
	}
    return 0;

}