#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		long long n;
		scanf("%lld", &n);

		while((n & 1) == 0){
			n >>= 1; 
		}
		
		if(n != 1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	

    return 0;

}