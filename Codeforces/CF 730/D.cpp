#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define SCALE (10e+6)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);

	int g = 0;
	for(int i = 0; i < n; i++){
		int a;
		printf("%d\n", (g^i));
		fflush(stdout);
		scanf("%d", &a);
		if(a == 1) return;
		g ^= (g^i);
	}
}


int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}