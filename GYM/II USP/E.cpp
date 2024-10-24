#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		a[i] = a[i-1] + x;
	}

	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d %d", &l, &r);

		if((a[r] - a[l-1]) % 2){
			printf("Nao\n");
		}
		else{
			printf("Sim\n");
		}
	}
	

    return 0;

}