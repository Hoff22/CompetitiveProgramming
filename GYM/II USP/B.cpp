#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int fodase;
		scanf("%d", &fodase);
	}

	int count = 1;
	while(n > 1){
		count++;
		n >>= 1;
	}

	printf("%d\n", count);
	

    return 0;

}