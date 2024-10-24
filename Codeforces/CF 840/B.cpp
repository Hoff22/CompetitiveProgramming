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
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> h(n);
	vector<pair<int,int>> p(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &h[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].fi);
		p[i].se = i;
	}

	sort(p.begin(), p.end());

	long long acc = k;
	for(int i = 0; i < n; i++){
		while(h[p[i].se] > acc and k > 0){
			k -= p[i].fi;
			acc += k;
		}
	}

	int mx = *max_element(h.begin(), h.end());

	if(mx <= acc){
		printf("YES\n");
	}
	else printf("NO\n");
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