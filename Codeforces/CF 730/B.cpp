#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long a[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	long long sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	//printf("%lld\n", sum);
	long long r = 0;
	for(int i = 0; i < n; i++){
		r += (a[i] - (sum/n));
	}

	long long ans = 0;

	for(int i = 0; i < r; i++){
		if(i < r){
			ans += (n - r);
		}
	}

	printf("%lld\n", ans);

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}