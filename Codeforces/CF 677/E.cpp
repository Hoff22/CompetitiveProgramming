#include <bits/stdc++.h>

#define N 20
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

long long fact[N+1];

long long choose[N+1][N+1];

void pascal(){
   for(int i = 0; i <= N; i++){
      choose[i][0] = 1;
   }
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= i; j++){
         choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) /*% MOD*/;
      }
   }
}

int main(){
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= N; i++){
		fact[i] = fact[i-1]*i;
	}
	pascal();

	int n;
	scanf("%d", &n);

	long long ans = choose[n][n/2] * fact[(n/2)-1] * fact[(n/2)-1];

	printf("%lld\n", ans/2);

    return 0;

}