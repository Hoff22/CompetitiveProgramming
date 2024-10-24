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

	int x = n%10 - 1;
	int y = 0;
	while(n){
		y++;
		n/=10;
	}

	int j = 0;
	int ans = 0;
	for(int i = 1; i <= 4*x + y; i++){
		ans += j+1;
		j++;
		j %= 4;
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