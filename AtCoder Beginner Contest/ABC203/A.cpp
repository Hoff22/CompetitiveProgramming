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
	
	int a[3];

	for(int i = 0; i <= 2; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < 3; i++){
		if(a[i] == a[(i+1)%3]){
			printf("%d\n", a[(i+2)%3]);
			return 0;
		}
	}

	printf("0\n");

    return 0;

}