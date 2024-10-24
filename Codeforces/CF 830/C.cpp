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

vector<long long> v;
vector<long long> s;
vector<long long> x;

bool comp(int v, int val){

	return (s[v] - x[v]) >= val;

}

void solve(){
	long long n, q;
	scanf("%lld %lld", &n, &q);

	v.resize(n+1);
	s.resize(n+1);
	x.resize(n+1);

	for(long long i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}

	s[0] = 0;
	x[0] = 0;
	for(int i = 1; i <= n; i++){
		s[i] = s[i-1] + v[i];
		x[i] = x[i-1] ^ v[i];
		v[i] = i;
	}

	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);

		int mx = s[r] - x[r];

		int i, j;

		j = lower_bound(v.begin() + l, v.begin() + r + 1, mx, comp1) - v.begin();
	}
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