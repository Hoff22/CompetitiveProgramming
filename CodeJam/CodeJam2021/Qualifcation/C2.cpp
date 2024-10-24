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

int r[N+1];
int ans[N+1];

void solve(int q){
	int n, c;
	scanf("%d%d", &n, &c);

	memset(r, 0, sizeof(r));

	if(c < n-1){
		printf("Case #%d: IMPOSSIBLE\n", q);
		return;
	}
	// n = 7
	// c = 7*(0-1) + 6*(0-2) + 5*(0-3) + 4*(0-4) + 3*(0-5) + 2*(0-6) + 1*(0-7)

	for(int i = 1; i <= n; i++){
		ans[i] = i;
	}


	for(int i = 1; i < n; i++){
		int k = n - i + 1;
		r[i] = min((c-k+2), k);
		c -= r[i];
	}

	if(c != 0){
		printf("Case #%d: IMPOSSIBLE\n", q);
		return;
	}

	for(int i = n-1; i >= 1; i--){
		// 0 1 2 3 4 5 6 7 8
		//                 ^
		reverse(ans+i, ans+i+r[i]);
	}
	printf("Case #%d: ", q);
	for(int i = 1; i <= n; i++){
		printf("%d", ans[i]);
		if(i != n) printf(" ");
		else printf("\n");
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}