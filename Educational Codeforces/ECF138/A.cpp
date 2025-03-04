#include <bits/stdc++.h>

#define N 8
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

	int f[N+1];
	int g[N+1];

	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));

	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		f[x] = 1;
		g[y] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(f[i] == 0 and g[j] == 0){
				printf("YES\n");
				return;
			}
		}
	}

	printf("NO\n");
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