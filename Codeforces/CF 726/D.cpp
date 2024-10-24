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
	
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);
		
		int x = n;

		int i = 0;
		while(x > 1 and x % 2 == 0){
			x /= 2;
			i++;
		}
		if(x > 1){
			if(n % 2) printf("Bob\n");
			else printf("Alice\n");
		}
		else{
			if(i % 2 or n == 1) printf("Bob\n");
			else printf("Alice\n");
		}
	}
    return 0;

}