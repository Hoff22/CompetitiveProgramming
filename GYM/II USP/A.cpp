#include <bits/stdc++.h>

#define N 1000
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

		long long a, b;
		bool ok = false;

		scanf("%lld %lld", &a, &b);


		for(long long i = 2; i * i <= min(a, b); i++){
			if(!(a % i) and !(b % i)){
				ok = true;
				break;
			}
		}

		if(max(a,b) % min(a,b) == 0){
			ok = true;
		}

		if(ok){
			printf("Sim\n");
		}
		else printf("Nao\n");

	}

    return 0;

}