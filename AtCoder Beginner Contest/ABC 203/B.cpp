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

int main(){
	
	int n, k;

	scanf("%d %d", &n, &k);


	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			ans += i*100 + j;
		}
	}

	printf("%lld\n", ans);

    return 0;

}