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
	
	int x, y;

	scanf("%d", &x);
	scanf("%d", &y);

	if(x == y) printf("%d\n", x);
	else{
		int a[3] = {0,0,0};
		a[x] = 1;
		a[y] = 1;
		for(int i = 0; i < 3; i++){
			if(!a[i]){
				printf("%d\n", i);
				break;
			}
		}
	}

    return 0;

}