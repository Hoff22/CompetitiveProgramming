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
	int n;
	scanf("%d", &n);

	vector<int> idx(n, 0);

	vector<vector<int>> p(n,vector<int>(n,0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			scanf("%d", &p[i][j]);
		}
	}

	vector<int> ans(n);

	for(int j = 0; j < n; j++){
		vector<int> cnt(n+1,0);
		int mx = 0;
		for(int i = 0; i < n; i++){
			cnt[p[i][j+idx[i]]]++;
			mx = max(mx, cnt[p[i][j+idx[i]]]);
		}

		for(int i = 0; i < n; i++){
			if(cnt[p[i][j]] != mx){
				p[i].insert(p[i].begin(),0);
				break;
			}
		}

		for(int i = 1; i <= n; i++){
			if(cnt[i] == mx){
				ans[j] = i;
				break;
			}
		}
	}

	for(int i : ans){
		printf("%d ", i);
	}
	printf("\n");
}

/*

4 2 1
  4 2 3
  2 1 3
  4 1 3

4   3
*/

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