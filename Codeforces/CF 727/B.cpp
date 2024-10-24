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

int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);

	for(int i = 1; i <= n; i++){
		char x;
		scanf(" %c", &x);

		a[i] = a[i-1] + (int)(x - 'a' + 1);
	}

	for(int i = 0; i < q; i++){
		int l, r;
		scanf("%d %d", &l , &r);

		printf("%lld\n", a[r] - a[l-1]);
	}

    return 0;

}