#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n;
	scanf("%d", &n);

	// if(n == 1){
	// 	printf("0\n");
	// 	return;
	// }

	int ans = INF;
	for(int i = 1; i*i <= n; i++){
		ans = min(ans , (int)ceil(1.0*(n-i)/i) + i - 1);
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}