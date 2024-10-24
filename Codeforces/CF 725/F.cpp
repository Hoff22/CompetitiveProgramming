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

// long long offsets[10] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

long long gordinho(int n){
	long long r = 0;
	long long offsets = 1;
	while(n){
		r += offsets * (n%10);
		n /= 10;
		offsets = offsets*10 + 1;
	}

	return r;
}

void solve(){
	int l, r;
	scanf("%d %d", &l, &r);

	printf("%lld\n", gordinho(r) - gordinho(l));

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}