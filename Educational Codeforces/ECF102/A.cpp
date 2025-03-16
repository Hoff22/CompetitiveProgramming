#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	if(n > k){
		printf("%d\n", 1 + (n % k != 0));
	}
	else{
		// n + (k - n);
		printf("%d\n", k/n + (k % n != 0));
	}
}

// k = i*n + c

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}