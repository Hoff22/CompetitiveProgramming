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
	int a, b;
	scanf("%d %d", &a, &b);

	if(a > b) swap(a, b);

	int x = a;

	int y = b-a;

	int ans = 0;
	ans += min(x, y/2);

	x -= ans;

	ans += x/2;

	printf("%d\n", ans);
}

/*

4x = a-x + b-x

4x = a+b - 2x

6x = a+b

x = a+b / 6

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