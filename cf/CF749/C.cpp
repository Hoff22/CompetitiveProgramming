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

char a[N+1][N+1];
int least[N+1];
int lef[N+1][N+1];
int x1, x2;
int n, m;

void solve(){
	scanf("%d %d", &x1, &x2);

	int mn = INF;
	for(int i = x1; i <= x2; i++){
		mn = min(mn, least[i]);
	}

	if(mn >= x1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int main(){
	
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);
		}
	}

	memset(lef, 0x3f, sizeof(lef));
	for(int j = 0; j < m; j++){
		int poss = 0;
		for(int i = 0; i < n; i++){
			if(a[i][j] == 'X'){
				lef[i][j] = 0;
				poss = 1;
			}
			
			if(poss and lef[i][j-1] != INF){
				lef[i][j] = j-1;
			}
		}
	}

	for(int j = 0; j < m; j++){
		int mn = INF;
		for(int i = 0; i < n; i++){
			mn = min(mn, lef[i][j]);
		}
		least[j] = mn;
	}

	int q;
	scanf("%d", &q);

	while(q--){
		solve();
	}

    return 0;

}