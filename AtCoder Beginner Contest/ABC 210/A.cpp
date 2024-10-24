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
	
	int n, a, x, y;
	scanf("%d%d%d%d", &n, &a, &x, &y);

	if(n > a){
		printf("%d\n", a*x + (n-a)*y);
	}
	else{
		printf("%d\n", n*x);
	}



    return 0;

}