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
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);

	int d = max(x,y);
	if(x + y == 0 or min(x, y) > 0 or (n-1) % d != 0){
		printf("-1\n");
		return;
	}

	for(int k = 0; k < d; k++){
		printf("%d ", 1);
	}
	for(int i = d+2; i <= n; i+=d){
		for(int k = 0; k < d; k++){
			printf("%d ", i);
		}
	}
	printf("\n");


}

/*

3
1 2 3 4  5 6 7  8 9 10   11 12
    1      5      8        11


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