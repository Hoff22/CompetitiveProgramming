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
		int n;

		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			if(i * 2 <= n){
				printf("%d ", n-i+1);
			}
			else{
				printf("%d ", i - (n/2));
			}
		}
	}

    return 0;

}