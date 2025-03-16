#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
	// n = 2021a + 2020b
	// n - 2020b = 2021*a

	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		int good = 0;

		scanf("%d", &n);

		int i = 0;
		while(n - 2020*i > 0){
			if((n - 2020*i) % 2021 == 0){
				good = 1;
				break;
			}

			i++;
		}

		if(n - 2020*i == 0) good = 1;

		if(good){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	

    return 0;

}