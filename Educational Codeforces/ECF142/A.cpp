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
	int n;
	scanf("%d", &n);

	int ans = 0;
	int ones = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(x == 1){
			ones++;
			if(ones % 2) ans++;
		}
		else{
			ans++;
		}
	}	

	printf("%d\n", ans);
}

/*

 1 2 2 2

 4 - (1) + 1

 4 - ()
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