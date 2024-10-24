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

int main(){
	
	int n;
	scanf("%d", &n);

	vector<pair<long long,long long>> p;

	int mx = 0;
	for(int i = 0; i < n; i++){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		p.push_back({a,b});
		if(p[mx].fi < p[i].fi) mx = i;
	}

	sort(p.begin(), p.end());

	long long ans = p[mx].fi;
	long long have = p[mx].fi - p[mx].se;
	for(int i = 0; i < n; i++){
		if(i == mx) continue;

		ans += max(p[i].fi - have, 0ll);
		have = max(have, p[i].fi);
		have -= p[i].se;
	}

	printf("%lld\n", ans);

    return 0;

}