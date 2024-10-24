#include <bits/stdc++.h>

#define N 100
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n;
	int ans[N+1][N+1];
	scanf("%d", &n);
	
	if(n == 2){
		printf("-1\n");
		return;
	}

	int x = 1;
	int d = 0;
	while(d <= n-1){

		for(int i = d; i < n; i++){
			ans[i][i-d] = x;
			x++;
		}

		if(d){
			for(int j = d; j < n; j++){
				ans[j-d][j] = x;
				x++;
			}
		}

		d++;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}