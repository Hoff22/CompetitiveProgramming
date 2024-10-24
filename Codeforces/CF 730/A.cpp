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
	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long of = abs(a - b);

	if(of == 0) printf("0 0\n");
	else printf("%lld %lld\n", of, min((a%of), of - (a%of)));
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}