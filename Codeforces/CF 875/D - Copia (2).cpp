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

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	vector<map<int,int>> cnt(N+1, map<int,int>());

	for(int i = 0; i < n; i++){
		cnt[a[i]][b[i]]++;
	}

	ll ans = 0;
	set<pair<int,int>> seen;
	for(int i = 0; i < n; i++){
		for(int d = 1; d * d <= b[i]; d++){
			if(b[i]%d == 0){
				
				int aj = d;
				int x = b[i]/aj;
				int y = a[i]-x;
				if(!seen.count({aj, y*aj})){
					if(cnt[aj].count(y*aj)) ans += cnt[aj][ y*aj ] - (a[i] == aj);
					seen.insert({aj, y*aj});
				}

				if(d*d != b[i]){
					aj = b[i]/d;
					x = b[i]/aj;
					y = a[i]-x;
					if(!seen.count({aj, y*aj})){
						if(cnt[aj].count(y*aj)) ans += cnt[aj][ y*aj ] - (a[i] == aj);
						seen.insert({aj, y*aj});
					}
				}
			}
		}
	}

	cout << ans << endl;
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