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

// 1 (n/2)		(n/2)	impar
// 0 (n/4)		(n/4)	par
// 
// n/2 é PAR 	=>		(n/2)	(n/4)	(n/4)
// n/2 é IMPAR 	=> 		2 (n/2)-1	(n/2)-1
void solve(){
	
	int n, k;

	scanf("%d %d", &n, &k);

	while(k > 3 and n > 0){
		printf("%d ", 1);
		n--;
		k--;
	}

	if(n%2){
		printf("%d %d %d\n", 1, n/2, n/2);
	}
	else{
		if(n%4 == 0){
			printf("%d %d %d\n", n/2, n/4, n/4);
		}
		else{
			printf("%d %d %d\n", 2, (n/2)-1, (n/2)-1);
		}
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}