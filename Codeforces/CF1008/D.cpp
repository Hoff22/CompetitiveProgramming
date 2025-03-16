#include <bits/stdc++.h>

#define N 30
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
char op[N+1][2];
ll v[N+1][2], d[N+1][2];


ll solve2(ll l, ll r, int beg){
	for(int i = beg; i < n; i++){
		ll ad = 0;
		if(op[i][0] == '+') ad += v[i][0];
		else ad += l * (v[i][0]-1);
		if(op[i][1] == '+') ad += v[i][1];
		else ad += r * (v[i][1]-1);

		if(d[i+1][0] > d[i+1][1]) l += ad;
		else r += ad;
	}
	return l+r;
}

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf(" %c %lld %c %lld ", &op[i][0], &v[i][0], &op[i][1], &v[i][1]);
	}

	d[n][0] = d[n][1] = 0;

	for(int i = n-1; i >= 0; i--){
		d[i][0] = solve2(1,0,i);
		d[i][1] = solve2(0,1,i);
	}

	printf("%lld\n", solve2(1,1,0));
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