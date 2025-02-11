#include <bits/stdc++.h>

#define N 500
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
	int n, k, r, c;
	scanf("%d %d %d %d", &n, &k, &r, &c);

	int a[N+1][N+1];

	memset(a, 0, sizeof(a));

	for(int j = c; j <= n; j+=k){
		a[r][j] = 1;
	}

	int stc = 1;
	for(int j = c; j >= 1; j-=k){
		a[r][j] = 1;
		stc = j;
	}

	int cur_cs = ((stc+1) % k);
	for(int i = r+1; i <= n; i++){
		if(cur_cs == 0) cur_cs = k;
		for(int j = cur_cs; j <= n; j+=k){
			a[i][j] = 1;
		}
		cur_cs = ((cur_cs+1) % k);
	}

	cur_cs = ((stc-1) % k);
	for(int i = r-1; i >= 1; i--){
		if(cur_cs == 0) cur_cs = k;
		for(int j = cur_cs; j <= n; j+=k){
			a[i][j] = 1;
		}
		cur_cs = ((cur_cs-1) % k);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j]) printf("X");
			else printf(".");
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