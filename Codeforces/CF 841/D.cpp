#include <bits/stdc++.h>

#define N 1000000
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

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			a[i][j] = min(a[i][j], 1000);
		}
	}

	int l = 1;
	int r = 1000;
	int ans = 0;

	while(l <= r){
		int mid = (l+r) / 2;

		vector<vector<int>> s(2, vector<int>(m+1, 0));

		int mx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){

				int cur = (a[i][j] >= mid);
				if(j > 1 and cur){
					cur = min({s[1][j-1], s[0][j-1], s[1][j]}) + 1;
				}

				s[0][j] = s[1][j];
				s[1][j] = cur;

				mx = max(mx, cur);
			}
		}

		if(mx >= mid){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}

	printf("%d\n", ans);

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