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

int n, m;
vector<vector<int>> a;

void solve(){
	scanf("%d %d", &n, &m);

	a.assign(n+1, vector<int>(m+1, 0));
	vector<vector<map<int,int>>> pref(n+1, vector<map<int,int>>(m+1));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			for(auto k : pref[i][j-1]){
				pref[i][j][k.first] += k.second;
			}
			for(auto k : pref[i-1][j]){
				pref[i][j][k.first] += k.second;
			}
			for(auto k : pref[i-1][j-1]){
				pref[i][j][k.first] -= k.second;
				if(pref[i][j][k.first] == 0){
					pref[i][j].erase(k.first);
				}
			}

			a[i][j] = min(a[i][j], 1000);

			pref[i][j][a[i][j]]++;
		}
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