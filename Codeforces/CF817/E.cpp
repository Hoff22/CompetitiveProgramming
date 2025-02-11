#include <bits/stdc++.h>

#define N 1000
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

vector<int> h[N+1];
vector<long long> sumH[N+1];

void solve(){
	int n, q;
	scanf("%d %d", &n, &q);

	for(int i = 1; i <= 1000; i++){
		h[i].clear();
	}

	for(int i = 1; i <= n; i++){
		int y, x;
		scanf("%d %d", &y, &x);

		h[y].push_back(x);
	}

	for(int i = 1; i <= 1000; i++){
		if(h[i].empty()) continue;

		sort(h[i].begin(), h[i].end());
		

		sumH[i].assign((int)h[i].size(), 0);

		sumH[i][0] = (1ll * h[i][0] * i);
		for(int j = 1; j < h[i].size(); j++){
			sumH[i][j] = 1ll * sumH[i][j-1] + (1ll * h[i][j] * i);
		}
	}

	while(q--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);


		long long ans = 0;
		for(int i = y1+1; i < y2; i++){

			if(h[i].empty()) continue;

			int l = (int)(upper_bound(h[i].begin(), h[i].end(), x1) - h[i].begin());
			int r = (int)(lower_bound(h[i].begin(), h[i].end(), x2) - h[i].begin()) - 1;

			if(l <= r){
				if(l == 0){
					ans += sumH[i][r];
				}
				else{
					ans += sumH[i][r] - sumH[i][l-1];
				}
			}

		}
		
		printf("%lld\n", ans);
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