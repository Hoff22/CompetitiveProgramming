#include <bits/stdc++.h>

#define N 262144
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

int a[N+1];
pair<int,int> tr[4*N+1];
int ans;
bool bad;

pair<int,int> build(int cur, int l, int r){
	int m = (l+r)/2;

	if(l == r){
		return tr[cur] = {a[l], a[l]};
	}

	pair<int,int> nl = build(LEFT(cur), l, m);
	pair<int,int> nr = build(RIGHT(cur), m+1, r);

	return tr[cur] = {min(nl.fi, nr.fi), max(nl.se, nr.se)};
}

void s(int cur, int l, int r){
	int m = (l+r)/2;

	if(l == r) return;

	if(tr[cur].fi < l or tr[cur].se > r){
		bad = true;
	}

	if(tr[LEFT(cur)].fi > tr[RIGHT(cur)].fi){
		ans++;
		s(RIGHT(cur), l, m);
		s(LEFT(cur), m+1, r);
	}
	else{
		s(LEFT(cur), l, m);
		s(RIGHT(cur), m+1, r);
	}
}

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	build(1, 1, n);

	bad = false;
	ans = 0;
	s(1, 1, n);

	if(bad){
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
	
	while(t--){
		solve();
	}
    return 0;

}