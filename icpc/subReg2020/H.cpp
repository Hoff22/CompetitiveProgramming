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

int main(){
	
	long long v, n;

	scanf("%lld %lld", &v, &n);

	long long p = v * n;

	for(int i = 1; i <= 9; i++){
		// 10x / p = 10i
		// 10x = 10i * p
		printf("%lld ", (i * p + 9)/10);

	}

    return 0;

}