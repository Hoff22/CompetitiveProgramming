#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);

	if(a){
		if(b){
			printf("Alloy\n");
		}
		else{
			printf("Gold\n");
		}
	}
	else{
		if(a){
			printf("Alloy\n");
		}
		else{
			printf("Silver\n");
		}
	}

    return 0;

}