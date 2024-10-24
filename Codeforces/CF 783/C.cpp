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

	long long b[N+1];
	for(int i = 0; i < n; i++){
		scanf("%lld", (b+i));
	}

	long long a[N+1];
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i < n; i++){
		long long cur = 0;
		a[i] = 0;
		for(int j = i-1; j >= 0; j--){
			long long x = (a[j+1] / b[j] + 1);
			cur += x;
			a[j] = x * b[j];
		}
		for(int j = i+1; j < n; j++){
			long long x = (a[j-1] / b[j] + 1);
			cur += x;
			a[j] = x * b[j];
		}
		ans = min(ans, cur);
		for(int j = 0; j < n; j++) printf("%lld ", a[j]);
		printf("\n");
	}
	printf("%lld\n", ans);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}