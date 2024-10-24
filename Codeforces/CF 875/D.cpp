#include <bits/stdc++.h>

#define N 400000
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

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<pair<ll,ll>> v(n);

	for(int i = 0; i < n; i++) cin >> v[i].fi;
	for(int i = 0; i < n; i++) cin >> v[i].se;

	vector<vector<int>> cnt(ceil(sqrt(2*n))+5, vector<int>(n+1, 0));

	for(int i = 0; i < n; i++){
		if(v[i].fi*v[i].fi <= 2*n){
			cnt[v[i].fi][v[i].se]++;
		}
	}

	ll a = 0;
	ll b = 0;
	for(int ai = 1; ai * ai <= 2*n; ai++){
		for(int j = 0; j < n; j++){
			int aj = v[j].fi;
			int bj = v[j].se;
			int bi = 1ll*ai*aj - bj;
			if(aj < ai) continue;
			if(bi <= 0 or bi > n) continue;
			if(aj == ai){
				if(bi == bj){
					b += cnt[ai][bi]-1;
				}
				else{
					b += cnt[ai][bi];
				}
			}
			else{
				a += cnt[ai][bi];
			}
		}
	}

	cout << a + b/2 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}