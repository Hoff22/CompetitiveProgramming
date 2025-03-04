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

// 12 min to solve

void solve(){
	int n, k1, k2;
	scanf("%d%d%d", &n, &k1, &k2);

	int w, b;
	scanf("%d%d", &w, &b);


	int g1 = n-k1;
	int g2 = n-k2;
	if(w*2 > k1+k2){
		printf("NO\n");
		return;
	}
	if(b*2 > g1+g2){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}