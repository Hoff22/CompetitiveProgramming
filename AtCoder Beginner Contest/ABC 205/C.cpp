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

int main(){
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if(c%2 == 0){ // even
		a = abs(a);
		b = abs(b);
	}
	if(a < b){
		printf("<\n");
	}
	else if(a > b){
		printf(">\n");
	}
	else{
		printf("=\n");
	}

    return 0;

}