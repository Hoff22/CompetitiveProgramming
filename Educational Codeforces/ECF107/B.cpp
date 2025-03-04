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

long long p10[11];

int sizeI(int n){
	int r = 0;
	while(n){
		r++;
		n/=10;
	}

	return r;
}

void solve(){
	int a, b, c;
	scanf("%d%d%d", &a,&b,&c);

	if(a > b) swap(a, b);

	int gcd = p10[c-1];

	if(c > 1){
		a = p10[a-1];
		b = (p10[b-c+1]-1)*p10[c-1];
	}
	else{
		b = p10[b-1]+1;
		a = p10[a-1];
	}

	printf("%d %d\n", a, b);
	//printf("gcd: %d\n", __gcd(a,b));

	// b / gcd <= b
	// a / gcd <= a 
}

int main(){
	
	p10[0] = 1;
	for(int i = 1; i <= 10; i++){
		p10[i] = p10[i-1]*10;
	}


	int t;
	scanf("%d", &t);
	



	while(t--){
		solve();
	}
    return 0;

}