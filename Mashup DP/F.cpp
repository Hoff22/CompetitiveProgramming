#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define e 2.71828182845904523
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

// N = max number n to compute n choose k;
// n choose k = choose[n][k]; 
long long choose[N+1][5];

void pascal(){
   for(int i = 0; i <= N; i++){
      choose[i][0] = 1;
   }
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= 4; j++){
         choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) /*% MOD*/;
      }
   }
}

int fact[5] = {1, 1, 2, 6, 24};

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	pascal();
	
	long long ans = 1;
	for(int i = k; i > 1; i--){
		ans += (long long)(choose[n][i] * round(1.0*fact[i]/e));
	}

	printf("%lld\n", ans);
}

int main(){
	
	solve();

    return 0;

}