#include <bits/stdc++.h>

#define N 100000000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
	
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);

	// Cyan + (x*b) <= (x*c) * d
	// xCyan + xB <= xCD
	// xCyan <= xCD - xB

	// x <= (xCD - xB) / Cyan

	long long j = 0;
	int i = 0;
	while(a > j*d and i <= N){
		j += c;
		a += b;
		i++;
	}
	if(a > j*d) printf("%d\n", -1);
	else printf("%d\n", i);

    return 0;

}