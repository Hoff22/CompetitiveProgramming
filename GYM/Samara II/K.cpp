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


void solve(){
	int n, m;
	scanf("%d %d", &n, &m);
	map<int,int> row[N+1];

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x;
			scanf("%d", &x);

			row[i][x]++;
		}

		for(auto r : row[i]){
			int x = r.fi;
			if(row[i-1].count(x)) ans += min(row[i-1][x], row[i][x]);
		}
	}

	printf("%lld\n", ans);

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}