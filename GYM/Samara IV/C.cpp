#include <bits/stdc++.h>

#define N 1000000
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

long long ans[N+1];

int main(){
	
	long long n;
	scanf("%lld", &n);

	memset(ans, -1, sizeof(ans));

	for(long long i = 0; i < n; i++){
		ans[(i*i)%n] = i;
	}

	for(int i = 0; i < n; i++){
		printf("%lld ", ans[i]);
	}
	printf("\n");
   
    return 0;

}