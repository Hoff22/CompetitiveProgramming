#include <bits/stdc++.h>

#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

long long exp(long long a, int b){
	long long ans = 1;
	while(b > 0){

		if(b & 1){
			ans = (ans%MOD) * (a%MOD);
		}

		a = (a%MOD) * (a%MOD);

		b >>= 1;
	}

	return ans;
}

int main(){
	
	long long a;
	int b, c;
	scanf("%lld %d %d", &a, &b, &c);

	printf("%lld\n", (exp(a, b)%MOD) / max(1 , (c%MOD)));

	return 0;
}