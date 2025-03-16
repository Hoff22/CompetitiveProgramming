#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
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

	long long ans = 0;
	long long cur = 1;

	char last = 'd';
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);

		if(c != last){
			cur = 1;
		}
		else{
			cur *= 2;
		}

		cur %= MOD;

		ans += cur;
		ans %= MOD;

		last = c;
	}

	printf("%lld\n", ans);
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