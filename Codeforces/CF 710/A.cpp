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

void solve(){
	long long n, m, x;
	scanf("%lld%lld%lld", &n, &m, &x);

	// (x - 1) % n = i
	// ((x - 1) / n) = j
	// by row x = m*j + i + 1

	long long i = (x-1) % n;
	long long j = (x - 1) / n;

	printf("%lld\n", 1ll*m*i + j + 1);

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}