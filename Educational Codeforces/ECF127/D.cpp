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
	int n, x;
	scanf("%d %d", &n, &x);
	int a[N+1];
	for(int i = 1; i <= n; i++) scanf("%d", (a+i));

	int mn, mx;
	mn = INF;
	mx = 0;
	for(int i = 1 ; i <= n; i++){
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	int ans = 0;

	for(int i = 1; i < n; i++){
		ans += abs(a[i] - a[i+1]);
	}

	if(mn > x){
		int cur = min(abs(a[1] - x), abs(a[n] - 1));
		for(int i = 1; i < n; i++){
			cur = min(cur, abs(a[i] - 1) + abs(a[i+1] - x));
		}
		cur += x - 1;
		printf("%d\n", ans + cur);
	}
	else{
		pair<int,int> seg1 = {1, mn-1};
		pair<int,int> seg2 = {mx+1, x};

		int cur1, cur2;

		if(abs(seg1.se - a[1]) + abs(seg2.fi - a[n]) < abs(seg1.fi - a[n]) + abs(seg2.se - a[1])){
			cur1 = abs(seg1.se - a[1]);
			cur2 = abs(seg2.fi - a[n]);
		}
		else{
			cur1 = abs(seg1.fi - a[n]);
			cur2 = abs(seg2.se - a[1]);	
		}

		if(cur1 + cur2 > abs(seg2.se - a[1]) + abs(seg2.fi - seg1.se)){
			cur1 = abs(seg2.fi - seg1.se);
			cur2 = abs(seg2.se - a[1]);
		}
		if(cur1 + cur2 > abs(seg1.fi - a[n]) + abs(seg2.fi - seg1.se)){
			cur1 = abs(seg1.fi - a[n]);
			cur2 = abs(seg2.fi - seg1.se);
		}

		cur1 = min(cur1, abs(mn - 1) + abs(mn - seg1.se));
		cur2 = min(cur2, abs(seg2.fi - mx) + abs(seg2.se - mx));
		cur1 += (seg1.se - seg1.fi);
		cur2 += (seg2.se - seg2.fi);
		//printf("%d %d %d\n", ans, cur1,  cur2);
		printf("%d\n", ans + cur1 * (seg1.fi <= seg1.se) + cur2 * (seg2.fi <= seg2.se));
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