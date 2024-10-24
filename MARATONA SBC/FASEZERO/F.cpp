#include <bits/stdc++.h>

#define N 300000
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

int a[N+1];
int b[N+1];
pair<int, long long> dp[N+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] += 1000;
	}
	

	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		b[i] += 1000;
	}

	for(int i = 1; i < N+1; i++){
		dp[i] = {INF, 0};
	}

	long long ans = 0;

	for(int i = 1; i <= n; i++){
		
		for(int)

	}

	printf("%lld\n", ans);

	return 0;

}