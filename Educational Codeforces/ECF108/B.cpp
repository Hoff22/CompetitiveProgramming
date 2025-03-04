#include <bits/stdc++.h>

#define N 100
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
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		int a = n-1 + n*(m-1);
		
		if(a == k){
			printf("YEs\n");
		}
		else{
			printf("NO\n");
		}

	}
    return 0;

}