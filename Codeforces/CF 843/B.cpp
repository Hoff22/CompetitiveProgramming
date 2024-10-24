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

	map<int,int> cnt;
	vector<vector<int>> a(n, vector<int>());

	for(int i = 0; i < n; i++){
		int k;
		scanf("%d", &k);

		for(int j = 0; j < k; j++){
			int x;
			scanf("%d",  &x);
			cnt[x]++;
			a[i].push_back(x);
		}
	}


	for(int i = 0; i < n; i++){
		int good = 1;
		for(int j = 0; j < a[i].size(); j++){
			if(cnt[a[i][j]] == 1){
				good = 0;
			}
		}
		if(good){
			printf("YES\n");
			return;
		}
		
	}

	printf("NO\n");
}

/*

100
011
001


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