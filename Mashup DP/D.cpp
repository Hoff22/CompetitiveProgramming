#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int l[N+1];
int t[N+1];
int a[N+1];

void solve(){
	int n, k;
	long long ans = 0;
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", &t[i]);
		if(t[i]) ans += a[i];
	}

	for(int i = 1; i <= n; i++){
		l[i] = l[i-1] + !(t[i]) * a[i];
	}
	// 0   0 0 5 5 10 14
	//     
	int mx = 0;
	for(int i = 1; i <= n-k+1; i++){
		mx = max(mx, l[i+k-1] - l[i-1]);
	}

	printf("%lld\n", ans+mx);
}

int main(){
	
		solve();
    return 0;

}