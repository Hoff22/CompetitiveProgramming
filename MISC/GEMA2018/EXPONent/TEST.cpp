#include <bits/stdc++.h>

#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

long long divs(long long a){
	long long count = 0;
	for(int i = 1; i * i <= a; i++){
		if(a % i == 0) count += 2;
		if(i * i == a) count -= 1;
	}

	return count;
}

int main(){	

	long long n;
	printf("fala o numero tio: ");
	scanf("%lld", &n);
	
	for(long long i = 1; i <= n; i++){
		printf("%lld tem %lld divisores\n", i, divs(i));
	}

	return 0;
}