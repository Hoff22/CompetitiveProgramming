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

void solve(){
	int n;
	scanf("%d", &n);

	long long ans = 2;
	for(int i = 3; i <= n; i++){
		if(i % 2 == 0) ans *= 2;
	}
	if(n % 2) ans = 0;
	printf("%lld\n", ans);
}

int main(){
	
	solve();
    
    return 0;
}