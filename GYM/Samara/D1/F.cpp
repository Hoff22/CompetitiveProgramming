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
	
	int n;
	scanf("%d", &n);

	printf("%d\n", (n+1)/2 + (n%2 == 0));

	for(int i = 1; i <= n; i+=2){
		printf("%d ", i);
	}
	if(n%2 == 0) printf("%d\n", n);
	else printf("\n");

    return 0;

}