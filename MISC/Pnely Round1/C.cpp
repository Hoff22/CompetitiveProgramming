#include <bits/stdc++.h>

#define N 100
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

vector<int> g[N+1];
set<int> ans[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	vector<pair<int,int>> order(n);

	for(int i = 1; i <= n; i++){
		g[i].clear();
		ans[i].clear();
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char x;
			scanf(" %c", &x);

			if(x == '1'){
				g[i].push_back(j);
			}
		}
	}

	for(int i = 0; i < n; i++){
		order[i] = {(int)g[i+1].size(), i+1};
	}

	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());

	int cur = 1;
	for(int i = 0; i < n; i++){

		int u = order[i].se;

		ans[u].insert(cur);

		//printf("inserting %d in %d set\n", cur, u);

		for(int j = 0; j < g[u].size(); j++){
			int v = g[u][j];
			ans[v].insert(cur);
			//printf("inserting %d in %d set\n", cur, v);
		}
		cur++;
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", (int)ans[i].size());
		for(int j : ans[i]){
			printf("%d ", j);
		}
		printf("\n");
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