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
	int n, x;
	scanf("%d %d", &n, &x);

	if(n <= 2){
		printf("1\n");
		return;
	}

	int ans = 1;
	while((ans * x + 2) < n) ans++;

	printf("%d\n", ans+1);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}