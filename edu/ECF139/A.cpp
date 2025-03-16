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

int p10[8] = {
	1,10,100,1000,10000,100000,1000000,10000000
};

void solve(){
	int n;
	scanf("%d", &n);

	int ans = 0;
	int i;
	for(i = 7; i >= 0; i--){
		if(n/p10[i] > 0){

			ans += (n/p10[i]);

			break;
		}
	}

	i--;
	while(i >= 0){
		ans += 9;
		i--;
	}

	printf("%d\n", ans);
}

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