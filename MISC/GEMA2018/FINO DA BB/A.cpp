#include <bits/stdc++.h>

#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

long long exp(int a, int b){
	long long r = a;

	if(b == 0) return 1;

	if(b % 2) return exp(a*a, b-1);

	r = exp(r, b/2);
	r *= r;

	return r;
}

int main(){
	
	int a, int b;
	scanf("%d %d", &a, &b);

	printf("%lld\n", exp(a,b));

	return 0;
}

// 4 3 - 0.75 seg
// 5 2 - 0.20 seg
// 6 1 - 0.16 seg + (0.2 * 5) = 1 + 1 - 1.2 = 0.8

// 4 2.2 - 0.55 seg
// 5 0.0 - 0.00 seg
// 6 0.8 - 0.13 seg