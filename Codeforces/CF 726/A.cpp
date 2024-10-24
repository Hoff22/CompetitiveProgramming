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

void solve(){
	int n;
	scanf("%d", &n);

	int sum = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		sum += x;
	}

	if(sum < n){
		printf("%d\n", 1);
	}
	else{
		printf("%d\n", sum - n);
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