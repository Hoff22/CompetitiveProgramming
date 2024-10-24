#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int main(){
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if(a+b+c == 2){
		if(!a) printf("A\n");
		if(!b) printf("B\n");
		if(!c) printf("C\n");
	}
	else if(a+b+c == 1){
		if(a) printf("A\n");
		if(b) printf("B\n");
		if(c) printf("C\n");
	}
	else{
		printf("*\n");
	}

    return 0;

}