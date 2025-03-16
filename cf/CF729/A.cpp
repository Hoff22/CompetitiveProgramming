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
	int odd = 0;
	int even = 0;
	for(int i = 0; i < 2*n; i++){
		int x;
		scanf("%d", &x);
		if(x%2) odd++;
		else even++;
	}

	if(even == odd) printf("Yes\n");
	else printf("No\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;
}