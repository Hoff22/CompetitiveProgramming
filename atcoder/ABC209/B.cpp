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
	
	int n,x;
	scanf("%d %d", &n,&x);

	for(int i = 1; i <= n; i++){
		int g;
		scanf("%d", &g);
		x -= g;
		if(i%2==0)x++;
	}

	if(x >= 0) printf("Yes\n");
	else printf("No\n");

    return 0;

}