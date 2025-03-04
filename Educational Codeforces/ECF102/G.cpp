#include <bits/stdc++.h>

#define N 500
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

long long choose[N][N];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);	

	for(int i = 0; i <= n; i++){
	   choose[i][0] = 1;
	}
	for(int i = 1; i <= n; i++){
	   for(int j = 1; j <= i; j++){
	      choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
	   }
	}

	printf("%lld\n", choose[n][k]);
	

    return 0;

}