#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

long long p10[10];
long long value[11];
long long n, k;

void solve(){
	scanf("%lld %lld", &n, &k);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		value[i] = p10[x];
	}
	sort(value, value+n);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(k < value[i+1] - value[i] or i == n-1){
			for(int j = i; j > 0; j--){
				ans += (k - (value[j] - value[j-1]) + 1) * p10[j];

				k -= (k - (value[j] - value[j-1]) + 1);
			}
			ans += k+1;
			break;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	
	p10[0] = 1;
	for(int i = 1; i <= 9; i++){
		p10[i] = p10[i-1] * 10;
	}

	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}