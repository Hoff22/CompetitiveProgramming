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
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);

	int r = min(a, b);
	b = max(a, b);

	if(((b / r) + (bool)(b % r)) - 1 <= d){
		printf("YES\n");
	}
	else{
		printf("NO\n");
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