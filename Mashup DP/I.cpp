#include <bits/stdc++.h>

#define N 500
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1][N+1];
int sums[N+1];
int n, m, q;

void solve(){
	int i, j;
	scanf("%d %d", &i, &j);

	if(a[i][j]){
		a[i][j] = 0;
	}
	else{
		a[i][j] = 1;
	}

	int cur = 0;
	int ls = 0;
	for(int k = 1; k <= m; k++){
		if(a[i][k]){
			cur+=1;
		}
		else{
			ls = max(ls, cur);
			cur = 0;
		}
	}
	ls = max(ls, cur);
	sums[i] = ls;

	int ans = 0;
	for(int k = 1; k <= n; k++){
		ans = max(ans, sums[k]);
	}

	printf("%d\n", ans);
}

int main(){
	
	scanf("%d %d %d", &n, &m, &q);

	for(int i = 1; i <= n; i++){
		int cur = 0;
		int ls = 0;
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j]) cur += 1;
			else{
				ls = max(ls, cur);
				cur = 0;
			}
		}
		ls = max(ls, cur);
		sums[i] = ls;
	}

	while(q--){
		solve();
	}
    
    return 0;
}