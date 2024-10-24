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
	int n, k, x, y;
	scanf("%d %d %d %d", &n, &k, &x, &y);

	vector<int> a(n+1);
	vector<int> b(n+1);
	for(int i = 1; i <= n; i++){
		char c;
		int p;
		scanf(" %c %d", &c, &p);
		if(c=='A'){
			a[i] = p;
			b[i] = p-x;
		}
		else{
			a[i] = p-y;
			b[i] = p;
		}
	}

	set< pair<int,int> , greater<pair<int,int>> > pq;

	for(int i = 1; i <= n; i++){
		pq.insert({a[i], i});
		pq.insert({b[i], i});
	}

	// for(auto i : pq){
	// 	if(i.fi == a[i.se]){
	// 		printf("%d : %d A\n", i.fi, i.se);
	// 	}
	// 	else{
	// 		printf("%d : %d B\n", i.fi, i.se);
	// 	}
	// }

	long long ans = 0;

	int ca = 0;
	int cb = 0;
	while(ca < k or cb < k){
		int best = (*pq.begin()).se;

		if(a[best] > b[best]){ // a player
			pq.erase({a[best], best});
			//printf("erasing %d %d\n", a[best], best);
			if(ca < k){
				//printf("add %d %d\n", a[best], best);
				ca++;
				pq.erase({b[best], best});
				b[best] = -INF;
				ans += a[best];
			}
			a[best] = -INF;
		}
		else{
			pq.erase({b[best], best});
			//printf("erasing %d %d\n", b[best], best);
			if(cb < k){
				//printf("add %d %d\n", b[best], best);
				cb++;
				pq.erase({a[best], best});
				a[best] = -INF;
				ans += b[best];
			}
			b[best] = -INF;
		}
	}

	printf("%lld\n", ans);

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